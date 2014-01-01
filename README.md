C M2X API Client
=========================

The [AT&T M2X](https://m2x.att.com/) API provides all the needed operations and methods to connect your devices to AT&T's M2X service. This client provides an easy to use interface for your favorite language, [C](http://www.open-std.org/jtc1/sc22/wg14/).


Getting Started
===============
1. Signup for an M2X Account: https://m2x.att.com/signup
2. Obtain your *Master Key* from the Master Keys tab of your Account Settings: https://m2x.att.com/account
3. Create your first Data Source Blueprint and copy its *Feed ID*: https://m2x.att.com/blueprints
4. Review the M2X API Documentation: https://m2x.att.com/developer/documentation/overview

If you have questions about any M2X specific terms, please consult the M2X glossary: https://m2x.att.com/developer/documentation/glossary


Setup
=====

The library is written in [C89](http://en.wikipedia.org/wiki/ANSI_C) standard. So you can use most of the C compiliers including gcc and clang to compile the source code. The only external dependency is [libcurl](http://curl.haxx.se/libcurl/), please refer to the documentation of your OS for how to install libcurl. In fact, most Linux distributions come with libcurl support natively.

To build the m2x-c library and the examples, follow the next steps:

```
$ git clone https://github.com/attm2x/m2x-c.git
$ cd m2x-c
$ git submodule update --init
$ make
$ make examples
```

If no errors occur, the M2X library will be in `m2x-c/m2x.a` file, the examples will be in `m2x-c/examples/` folder. Feel free to link and use the m2x library in your own executables.

API
===

## Initialization

To use M2X C library, you need to first create a M2X context using the following function:

```
m2x_context *m2x_open(const char *key);
```

This function resides in `m2x.h` header file. The only argument to this function is your M2X API key, which you can obtain from the M2X website.

## Reader functions

After initialzing, you can call all kinds of M2X API functions. For example, the following function in `feed.h` can be used to get a list of your feeds:

```
int m2x_feed_list(m2x_context *ctx, const char *query, char **out);
```

With the second argument `query`, you can pass in arguments to filter what feeds you want to show. The supported variables are listed at [here](https://m2x.att.com/developer/documentation/feed#List-Search-Feeds). For now, you need to organize the query in query string format by hand. For example, the following query string can be used:

```
q=abc&page=2&limit=3
```

The results of the API function will be stored in a char buffer, it will be returned via the `out` pointer. **The caller of the function is responsible for releasing the buffer**. This can be done using the `m2x_free` function as listed below:

```
char *out = NULL;
m2x_feed_list(ctx, NULL, &out);
m2x_free(out);
```

Notice we are passing `NULL` here to the `query` argument, this means we are not adding any filter to the function.

If you don't care about the returned value of the API function, you can simply pass `NULL` to the `out` parameter. No buffers are needed to be freed in this case.

## Writer functions

You can also send data to M2X service using the C library. The following function can be used to update stream values:

```
int m2x_feed_update_stream(m2x_context *ctx, const char *feed_id,
                           const char *stream_name, const char *data,
                           char **out);
```

`feed_id` and `stream_name` are just plain feed id and stream name used. Notice that the C library will help you encode the data here. So if your stream name has a space in it(for example, `my stream 1`), there's no need to escape that before calling this function.

You can pass the data you want to send to M2X using `data` parameter here. For now, the M2X C library only support JSON string format. You need to either create the JSON string by hand(like the examples provided), or use a [JSON builder](http://www.json.org/) to create one.

As the reader functions, you can also use the `out` parameter here to get the output from M2X. However, for writer functions, we don't always care about what is returned from the server. A `NULL` value can be used in this case.


## JSON Deserializer

Besides the normal way of returning raw JSON strings, we also include [parson](https://github.com/kgabis/parson) to help parse the returned values and return JSON objects to ease programmer's work.

For each M2X API function, we also have a JSON variant, which is prefixed as `m2x_json_...`, which returns a `JSON_Value *` typed sturct. You can use the [APIs](https://github.com/kgabis/parson/blob/master/parson.h) provided by parson to peek into this struct and get all kinds of values in this JSON object/array very easily.

You can refer to the example `read_feeds` for a rough idea on how to use the parson library.

We may also add a JSON Serializer to help you prepare the JSON string to send to M2X in the future.

## Verbose mode

To help debugging M2X API functions, M2X library supports a verbose mode. You can use the following code to turn it on:

```
m2x_set_verbose(ctx, 1);
```

When verbose mode is on, M2X C library will print a lot of debugging information from libcurl to `stdout`. An example of the output looks like this:

```
* Adding handle: conn: 0x7fdc33004400
* Adding handle: send: 0
* Adding handle: recv: 0
* Curl_addHandleToPipeline: length: 1
* - Conn 0 (0x7fdc33004400) send_pipe: 1, recv_pipe: 0
* About to connect() to api-m2x.att.com port 80 (#0)
*   Trying 54.214.25.232...
* Connected to api-m2x.att.com (54.214.25.232) port 80 (#0)
> POST /v1/datasources HTTP/1.1
Host: api-m2x.att.com
Accept: */*
User-Agent: M2X/0.0.1 (C libcurl)
Content-Type: application/json
X-M2X-KEY: b3e742805ac8576d0df925b4dfe4d401
Content-Length: 81

* upload completely sent off: 81 out of 81 bytes
< HTTP/1.1 201 Created
< Content-Type: application/json
< Date: Wed, 01 Jan 2014 06:01:55 GMT
< Location: /datasources/a23c1d4445f52fdd8bccfac7bcc790a7
* Server nginx/1.1.19 is not blacklisted
< Server: nginx/1.1.19
< Status: 201 Created
< Vary: Accept-Encoding
< X-M2X-VERSION: v1.0.0-beta
< Content-Length: 398
< Connection: keep-alive
<
* Connection #0 to host api-m2x.att.com left intact
{"id":"a23c1d4445f52fdd8bccfac7bcc790a7","name":"abc","description":"def","visibility":"public","serial":null,"status":"enabled","feed":"/feeds/a23c1d4445f52fdd8bccfac7bcc790a7","tags":["123","456"],"url":"/datasources/a23c1d4445f52fdd8bccfac7bcc790a7","key":"0b28a57c811858f4c087fa3720e6f297","created":"2014-01-01T06:01:55Z","updated":"2014-01-01T06:01:55Z","batch":"/batches/","batch_name":null}

...
```

To turn the verbose mode off, use the following code:

```
m2x_set_verbose(ctx, 0);
```
