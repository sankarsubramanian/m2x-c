/** @file collection.h
 *  @brief Wrapper for AT&T M2X <a href="https://m2x.att.com/developer/documentation/v2/collections">Collections API</a>
 */
#ifndef M2X_COLLECTION_H
#define M2X_COLLECTION_H

#include "response.h"

#if defined(__cplusplus)
extern "C" {
#endif

/** @brief Method for <a href="https://m2x.att.com/developer/documentation/v2/collections#List-collections">List collections</a> endpoint
 * @param ctx - m2x_context structure
 * @param query - Query parameters passed as keyword arguments. View M2X API Docs for listing of available parameters
 * @return m2x_response - The API response, see M2X API docs for details
 */
m2x_response m2x_collection_list(m2x_context *ctx, const char *query);
/** @brief Method for <a href="https://m2x.att.com/developer/documentation/v2/collections#Create-Collection">Create Collection</a> endpoint
 * @param ctx - m2x_context structure
 * @param data - Query parameters passed as keyword arguments. View M2X API Docs for listing of available parameters
 * @return m2x_response - The API response, see M2X API docs for details
 */
m2x_response m2x_collection_create(m2x_context *ctx, const char *data);
/** @brief Method for <a href="https://m2x.att.com/developer/documentation/v2/collections#View-Collection-Details">View Collection Details</a> endpoint
 * @param ctx - m2x_context structure
 * @param collection_id (str) - ID of the Collection to get details
 * @return m2x_response - The API response, see M2X API docs for details
 */
m2x_response m2x_collection_view(m2x_context *ctx, const char *collection_id);
/** @brief Method for <a href="https://m2x.att.com/developer/documentation/v2/collections#Update-Collection-Details">Update Collection Details</a> endpoint
 * @param ctx - m2x_context structure
 * @param collection_id (str) - ID of the Collection to update details
 * @param data - Query parameters passed as keyword arguments. View M2X API Docs for listing of available parameters
 * @return m2x_response - The API response, see M2X API docs for details
 */
m2x_response m2x_collection_update(m2x_context *ctx, const char *collection_id,
                                   const char *data);
/** @brief Method for <a href="https://m2x.att.com/developer/documentation/v2/collections#Add-device-to-collection">Add device to collection</a> endpoint
 * @param ctx - m2x_context structure
 * @param collection_id (str) - ID of the Collection to add device
 * @param device_id (str) - ID of the device to add in Collection
 * @param data - Query parameters passed as keyword arguments. View M2X API Docs for listing of available parameters
 * @return m2x_response - The API response, see M2X API docs for details
 */
m2x_response m2x_collection_add_device(m2x_context *ctx, const char *collection_id,
                                     const char *device_id, const char *data);
/** @brief Method for <a href="https://m2x.att.com/developer/documentation/v2/collections#Remove-device-from-collection">Remove device from collection</a> endpoint
 * @param ctx - m2x_context structure
 * @param collection_id (str) - ID of the Collection to remove device
 * @param device_id (str) - ID of the device to remove from Collection
 * @param data - Query parameters passed as keyword arguments. View M2X API Docs for listing of available parameters
 * @return m2x_response - The API response, see M2X API docs for details
 */
m2x_response m2x_collection_remove_device(m2x_context *ctx, const char *collection_id,
                                    const char *device_id, const char *data);
/** @brief Method for <a href="https://m2x.att.com/developer/documentation/v2/collections#Delete-Collection">Delete Collection</a> endpoint
 * @param ctx - m2x_context structure
 * @param collection_id (str) - ID of the Collection to delete
 * @return m2x_response - The API response, see M2X API docs for details
 */
m2x_response m2x_collection_delete(m2x_context *ctx, const char *collection_id);
/** @brief Method for <a href="https://m2x.att.com/developer/documentation/v2/collections#Read-Collection-Metadata">Read Collection Metadata</a> endpoint
 * @param ctx - m2x_context structure
 * @param collection_id (str) - ID of the Collection to read metadata
 * @return m2x_response - The API response, see M2X API docs for details
 */
m2x_response m2x_collection_metadata(m2x_context *ctx, const char *collection_id);
/** @brief Method for <a href="https://m2x.att.com/developer/documentation/v2/collections#Update-Collection-Metadata">Update Collection Metadata</a> endpoint
 * @param ctx - m2x_context structure
 * @param collection_id (str) - ID of the Collection to update metadata
 * @param data - Query parameters passed as keyword arguments. View M2X API Docs for listing of available parameters
 * @return m2x_response - The API response, see M2X API docs for details
 */
m2x_response m2x_collection_metadata_update(m2x_context *ctx,
                                            const char *collection_id,
                                            const char *data);
/** @brief Method for <a href="https://m2x.att.com/developer/documentation/v2/collections#Read-Collection-Metadata-Field">Read Collection Metadata Field</a> endpoint
 * @param ctx - m2x_context structure
 * @param collection_id (str) - ID of the Collection to read metadata field
 * @param field (str) - Field to read metadata
 * @return m2x_response - The API response, see M2X API docs for details
 */
m2x_response m2x_collection_metadata_field(m2x_context *ctx,
                                           const char *collection_id,
                                           const char *field);
/** @brief Method for <a href="https://m2x.att.com/developer/documentation/v2/collections#Update-Collection-Metadata-Field">Update Collection Metadata Field</a> endpoint
 * @param ctx - m2x_context structure
 * @param collection_id (str) - ID of the Collection to update metadata field
 * @param field (str) - Field to update metadata
 * @param data (str) - The value to update
 * @return m2x_response - The API response, see M2X API docs for details
 */
m2x_response m2x_collection_metadata_field_update(m2x_context *ctx,
                                                  const char *collection_id,
                                                  const char *field,
                                                  const char *data);
/** @brief Method for <a href="https://m2x.att.com/developer/documentation/v2/collections#List-Devices-from-an-existing-Collection">List Devices from an existing Collection</a> endpoint
 * @param ctx - m2x_context structure
 * @param collection_id (str) - ID of the Collection to retrieve list of devices
 * @param query - Query parameters passed as keyword arguments. View M2X API Docs for listing of available parameters
 * @return m2x_response - The API response, see M2X API docs for details
 */
m2x_response m2x_collection_device_list(m2x_context *ctx, const char *collection_id, const char *query);


#if defined(__cplusplus)
}  /* extern "C" { */
#endif

#endif  /* M2X_COLLECTION_H */
