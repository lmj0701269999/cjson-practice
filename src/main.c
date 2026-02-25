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

       cJSON *root=cJSON_Parse(xiangmu1);
       if(root==NULL){
       printf("failed\n");
       return 1;
	   }else{
              printf("success\n");
              cJSON *student=cJSON_GetObjectItem(root,"student");
              cJSON *name = cJSON_GetObjectItem(student, "name");
              cJSON *age  = cJSON_GetObjectItem(student, "age");
              if(cJSON_IsString(name)&&cJSON_IsNumber(age)){
              	 printf("name:%s\n",name->valuestring);
              	 printf("age:%d\n",age->valueint);
             	
			  }
           }

cJSON_Delete(root);
return 0;

}
