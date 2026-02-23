#include <stdio.h>
#include <stdlib.h>
#include "cJSON.h"

int main(void)
{
    const char *xiangmu1=
    "{\n"
        "  \"student\": {\n"
        "    \"name\": \"lmj\",\n"
        "    \"age\": 20\n"
        "  },\n"
        "  \"courses\": [\n"
        "    { \"name\": \"math\",    \"score\": 89 },\n"
        "    { \"name\": \"English\", \"score\": 84 },\n"
        "    { \"name\": \"C\",       \"score\": 88 },\n"
        "    { \"name\": \"history\",  \"score\":90 },\n"
        "    { \"name\": \"basketball\",  \"score\":96 }\n"
        "  ]\n"
        "}\n";

cJSON *root=cJSON_parse(xiangmu1);
if(root==NULL){
printf(“failed\n”);
return 1;
}else{
 Printf(“success”\n);
}
   
   cJSON_Delete(root);
    return 0;
}
cat > src/main.c
#include <stdio.h>
#include <stdlib.h>
#include "cJSON.h"

int main(void)
{
    const char *xiangmu1=
    "{\n"
        "  \"student\": {\n"
        "    \"name\": \"lmj\",\n"
        "    \"age\": 20\n"
        "  },\n"
        "  \"courses\": [\n"
        "    { \"name\": \"math\",    \"score\": 89 },\n"
        "    { \"name\": \"English\", \"score\": 84 },\n"
        "    { \"name\": \"C\",       \"score\": 88 },\n"
        "    { \"name\": \"history\",  \"score\":90 },\n"
        "    { \"name\": \"basketball\",  \"score\":96 }\n"
        "  ]\n"
        "}\n";

cJSON *root=cJSON_parse(xiangmu1);
if(root==NULL){
printf(“failed\n”);
return 1;
}else{
 Printf(“success\n”);
}
   
   cJSON_Delete(root);
    return 0;
}
gcc src/main.c third_party/cJSON/cJSON.c -Ithird_party/cJSON -o build/app
./build/app
./build/app
echo $?
