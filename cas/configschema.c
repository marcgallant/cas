#include "configschema.h"

#include <stdio.h>
#include <stdlib.h>

#include "cJSON.h"

int file_version = 0;
int compatible_file_version = 0;

//TODO return error code
void load_schema() {
    FILE *f = fopen("schema-kas.json", "rb");
    if (f == NULL)
        return;

    fseek(f, 0, SEEK_END);
    long fsize = ftell(f);
    fseek(f, 0, SEEK_SET);

    char *string = malloc(fsize + 1);
    fread(string, fsize, 1, f);
    fclose(f);

    string[fsize] = 0;

    cJSON *json = cJSON_Parse(string);
    const char *error_ptr = cJSON_GetErrorPtr();
    if (error_ptr != NULL)
    {
        fprintf(stderr, "Error before: %s\n", error_ptr);
        return;
    }

    //header_node = CONFIGSCHEMA['properties']['header'];
    //__file_version__ = version_node["maximum"]
    //__compatible_file_version__ = version_node["minimum"]

    const cJSON *properties = cJSON_GetObjectItemCaseSensitive(json, "properties");
    if (!cJSON_IsObject(properties)) {
        printf("error1\n");
        return;
    }

    const cJSON *header = cJSON_GetObjectItemCaseSensitive(properties, "header");
    if (!cJSON_IsObject(properties)) {
        printf("error2\n");
        return;
    }

    const cJSON *properties2 = cJSON_GetObjectItemCaseSensitive(header, "properties");
    if (!cJSON_IsObject(properties2)) {
        printf("error3\n");
        return;
    }

    const cJSON *version = cJSON_GetObjectItemCaseSensitive(properties2, "version");
    if (!cJSON_IsObject(version)) {
        printf("error4\n");
        return;
    }

    const cJSON *anyOf = cJSON_GetObjectItemCaseSensitive(version, "anyOf");
    if (!cJSON_IsArray(anyOf) || cJSON_GetArraySize(anyOf) <= 1) {
        printf("error5\n");
        return;
    }

    const cJSON *version_node = cJSON_GetArrayItem(anyOf, 1);
    if (!cJSON_IsObject(version_node))  {
        printf("error6\n");
        return;
    }
 
    const cJSON *maximum = cJSON_GetObjectItemCaseSensitive(version_node, "maximum");
    if (!cJSON_IsNumber(maximum)) {
        printf("error7\n");
        return;
    }

    const cJSON *minimum = cJSON_GetObjectItemCaseSensitive(version_node, "minimum");
    if (!cJSON_IsNumber(minimum)) {
        printf("error8\n");
        return;
    }

    file_version = maximum->valueint;
    compatible_file_version = minimum->valueint;

    cJSON_Delete(json);

    free(string);
    return;
}
