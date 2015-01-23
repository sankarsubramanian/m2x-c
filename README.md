C M2X API Client
=========================

The [AT&T M2X](https://m2x.att.com/) API provides all the needed operations and methods to connect your devices to AT&T's M2X service. This client provides an easy to use interface for your favorite language, [C](http://www.open-std.org/jtc1/sc22/wg14/).


Getting Started
===============
1. Signup for an M2X Account: https://m2x.att.com/signup
2. Obtain your *Master Key* from the Master Keys tab of your Account Settings: https://m2x.att.com/account
3. Create your first Device and copy its *Device ID*: https://m2x.att.com/devices
4. Review the M2X API Documentation: https://m2x.att.com/developer/documentation/v2/overview

If you have questions about any M2X specific terms, please consult the M2X glossary: https://m2x.att.com/developer/documentation/v2/glossary


Setup
=====

The library is written in [C89](http://en.wikipedia.org/wiki/ANSI_C) standard. So you can use most C compilers, including gcc and clang, to compile the source code. The only external dependency is [libcurl](http://curl.haxx.se/libcurl/) (please refer to the documentation for your OS for instructions on how to install libcurl). In fact, most Linux distributions come with libcurl support natively.

To build the m2x-c library and the examples, follow the next steps:

```
$ git clone https://github.com/attm2x/m2x-c.git
$ cd m2x-c
$ git submodule update --init
$ make
$ make examples
```

If no errors occur, the M2X library will be in the `m2x-c/m2x.a` file and the examples will be in `m2x-c/examples/` folder. Feel free to link and use the m2x library in your own executables.

API
===

## Initialization

To use the M2X C library, you need to first create an M2X context using the following function:

```
m2x_context *m2x_open(const char *key);
```

This function resides in `m2x.h` header file. The only argument to this function is your M2X API key, which you can obtain from the [M2X website](https://m2x.att.com).

## Calling API functions

All API functions will have the following type of signature:

```
m2x_response m2x_some_api_function(m2x_context *ctx, const char *arg1, const char *arg2, ...);
```

Depending the exact function in use, different number of arguments may be present. For example, below is a function used to list stream values of a device:

```
m2x_response m2x_device_stream_list_values(m2x_context *ctx, const char *id, const char *name, const char *query);
```

It requires the context object, device ID, stream name and a query string. The query string is the same you would normally see in an HTTP request, like the following:

```
max=100&limit=10
```

We will talk about `m2x_response` in the next section.

## Response object

All API functions will return an `m2x_response` object. This object contains the status code, raw response as well as JSON-parsed response. The type of this object is as follows:

```
typedef struct m2x_response {
  int status;
  /* Raw response from server */
  char *raw;
  /* Parsed JSON representation */
  JSON_Value *json;
} m2x_response;
```

* `status` contains the same status code as those you can see in an HTTP request
* `raw` contains the raw reply from the API server (not necessarily NULL-terminated)
* `data` contains the reply in JSON format

The library for parsing JSON we use here is [parson](https://github.com/kgabis/parson). However, with the help of `raw` field, you can parse the response using any JSON parser you like. The `expand_json` member of the `m2x_content` object defaults to 1, which indicates that parson *will* be used to parse JSON reply. If you change this field to 0, parson *will not* be used to parse the raw reply, allowing you to use your own parsing code/library.

A handful of helpers are created for better usage of this object:

```
int m2x_is_success(const m2x_response *response);
int m2x_is_client_error(const m2x_response *response);
int m2x_is_server_error(const m2x_response *response);
int m2x_is_error(const m2x_response *response);
void m2x_release_response(m2x_response *response);
```

Notice `m2x_release_response` only frees the internal `raw` and `json` fields. There's no need to free any `m2x_response` object, since it is always passed by value.

## Writer functions

You can also send data to M2X service using the C library. The following function can be used to update stream values:

```
m2x_response m2x_device_stream_post_values(m2x_context *ctx, const char *device_id,
                                           const char *stream_name, const char *data);
```

`device_id` and `stream_name` are just the plain text Device ID and Stream that you are writing to. Notice that the C library will help you encode the data here, so if your Stream name has a space in it (for example, `my stream 1`), there's no need to escape that before calling this function.

You can pass the data you want to send to M2X using the `data` parameter here. For now, the M2X C library only supports JSON string format. You need to either create the JSON string by hand (like in the provided examples), or use a [JSON builder](http://www.json.org/) to create one. In addition, we also provide a JSON serializer that you can use to build such a JSON string.

## JSON Serializer

In the M2X C library, we provide a JSON serializer implementation to help you build JSON strings that you can use in writer functions. With the JSON serializer, you can easily build a JSON array or object containing arbitrary levels of (nested) data structure. All data types in JSON (null, boolean, number and string) are supported. Please refer to [serialize_json](https://github.com/attm2x/m2x-c/blob/master/examples/serialize_json.c) for an example of how to use the library.

It's worth mentioning that since floating point numbers (such as double) may contain as many as several hundred bytes, we don't yet have a native function for packing arbitrary double values in the JSON serializer. If you really do want to use double, you can specify your own precision level, use `sprintf` to keep it in a char buffer and then use `json_pack_value` to pack the data.

## Verbose mode

To help in debugging M2X API functions, the M2X C library supports a verbose mode. You can use the following code to turn it on:

```
m2x_set_verbose(ctx, 1);
```

When verbose mode is on, the M2X C library will print debugging information from libcurl to `stdout`. An example of the output looks like this:

```
* Hostname was NOT found in DNS cache
*   Trying 76.198.15.58...
* Connected to api-m2x.att.com (76.198.15.58) port 80 (#0)
> POST /v2/devices HTTP/1.1
Host: api-m2x.att.com
Accept: */*
User-Agent: M2X/2.0.0 (C libcurl)
Content-Type: application/json
X-M2X-KEY: b3e742805ac8576d0df925b4dfe4d401
Content-Length: 115

* upload completely sent off: 115 out of 115 bytes
< HTTP/1.1 201 Created
* Server nginx is not blacklisted
< Server: nginx
< Date: Sat, 20 Dec 2014 06:08:21 GMT
< Content-Type: application/json
< Content-Length: 451
< Status: 201 Created
< Location: http://api-m2x.att.com/v2/devices/0920125bea7fa9e42484faf86c75496e
< X-M2X-VERSION: v2.4.0-alpha
< Vary: Accept-Encoding
<
* Connection #0 to host api-m2x.att.com left intact
Status code: 201
{"url":"http://api-m2x.att.com/v2/devices/0920125bea7fa9e42484faf86c75496e","name":"Sample Device","status":"enabled","serial":null,"groups":["sample"],"location":{},"visibility":"public","description":"This is a sample M2X Device","created":"2014-12-20T06:08:21.752Z","updated":"2014-12-20T06:08:21.752Z","id":"0920125bea7fa9e42484faf86c75496e","streams":{"count":0,"url":"http://api-m2x.att.com/v2/devices/0920125bea7fa9e42484faf86c75496e/streams"}}
```

To turn the verbose mode off, use the following code:

```
m2x_set_verbose(ctx, 0);
```

## License

The M2X C Client is available under the MIT license. See the LICENSE file for more information.
