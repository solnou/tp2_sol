#include <stdio.h>
#include <stdlib.h>

#include <cjson/cJSON.h>

int main(void)
{

    cJSON* root = cJSON_CreateObject();

    cJSON_AddStringToObject(root, "name", "cJSON");
    cJSON_AddNumberToObject(root, "version", 1.7);
    cJSON_AddBoolToObject(root, "is_open_source", 0);

    cJSON* author = cJSON_CreateArray();

    cJSON_AddItemToArray(author, cJSON_CreateString("Sol"));
    cJSON_AddItemToArray(author, cJSON_CreateString("Coni"));
    cJSON_AddItemToArray(author, cJSON_CreateString("Nacho"));
    cJSON_AddItemToObject(root, "author", author);

    char* json_string = cJSON_Print(root);
    printf("%s\n", json_string);

    cJSON_Delete(root);
    free(json_string);

    return 0;
}
