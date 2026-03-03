#include <stdio.h>
#include <stdlib.h>
#include "cJSON.h"

int main(void){
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
       
       cJSON *courses=cJSON_GetObjectItem(root,"courses");
           if(cJSON_IsArray(courses)){
           printf("found courses successfully\n");
		}
    
       int size=cJSON_GetArraySize(courses);
           int sum=0;
           double averagescore=0.0;
           int highestscore=-100;
           char *highestcourse=NULL;
           for(int i=0;i<size;i++){
           cJSON *course=cJSON_GetArrayItem(courses,i);
           cJSON *nameofcourse=cJSON_GetObjectItem(course,"name");
           cJSON *scoreofcourse=cJSON_GetObjectItem(course,"score");
           if(cJSON_IsString(nameofcourse)&&cJSON_IsNumber(scoreofcourse)){
           	    printf("course:%s,score:%d\n",nameofcourse->valuestring,scoreofcourse->valueint);
           	    sum=sum+scoreofcourse->valueint;
           	    if(scoreofcourse->valueint>highestscore){
           	    	  highestscore=scoreofcourse->valueint;
           	    	  highestcourse=nameofcourse->valuestring;
           	    	}
		   }
		}
		
       averagescore=(double)sum/size;
       printf("平均分为:%.2f\n",averagescore);
       printf("最高分课程: %s, 分数: %d\n", highestcourse,highestscore);

cJSON_Delete(root);
return 0;

}  



