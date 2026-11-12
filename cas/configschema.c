#include "configschema.h"

#include <stdio.h>
#include <stdlib.h>

#include "cJSON.h"

int file_version = 0;
int compatible_file_version = 0;

int load_schema() {
    FILE *f = fopen("schema-kas.json", "rb");
    if (f == NULL) return 0;

    fseek(f, 0, SEEK_END);
    long fsize = ftell(f);
    fseek(f, 0, SEEK_SET);

    char *string = malloc(fsize + 1);
    fread(string, fsize, 1, f);
    fclose(f);

    string[fsize] = 0;

    cJSON *json = cJSON_Parse(string);
    const char *error_ptr = cJSON_GetErrorPtr();
    if (error_ptr != NULL) return 0;

    const cJSON *properties = cJSON_GetObjectItemCaseSensitive(json, "properties");
    if (!cJSON_IsObject(properties)) return 0;

    const cJSON *header = cJSON_GetObjectItemCaseSensitive(properties, "header");
    if (!cJSON_IsObject(properties)) return 0;

    const cJSON *properties_node = cJSON_GetObjectItemCaseSensitive(header, "properties");
    if (!cJSON_IsObject(properties_node))  return 0;

    const cJSON *version = cJSON_GetObjectItemCaseSensitive(properties_node, "version");
    if (!cJSON_IsObject(version)) return 0;

    const cJSON *list = cJSON_GetObjectItemCaseSensitive(version, "anyOf");
    if (!cJSON_IsArray(list) || cJSON_GetArraySize(list) <= 1) return 0;

    const cJSON *version_node = cJSON_GetArrayItem(list, 1);
    if (!cJSON_IsObject(version_node)) return 0;
 
    const cJSON *maximum = cJSON_GetObjectItemCaseSensitive(version_node, "maximum");
    if (!cJSON_IsNumber(maximum)) return 0;

    const cJSON *minimum = cJSON_GetObjectItemCaseSensitive(version_node, "minimum");
    if (!cJSON_IsNumber(minimum)) return 0;

    file_version = maximum->valueint;
    compatible_file_version = minimum->valueint;

    cJSON_Delete(json);

    free(string);
    return 1;
}
