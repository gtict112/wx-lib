// wx-lib.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#pragma comment(lib,"sqlcipher.lib")
#include "sqlite3.h"

static int simpleCallback(void* data, int argc, char** argv, char** azColName) {
    int i;
    fprintf(stderr, "%s: ", (const char*)data);
    for (i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}


int main()
{
  //  unsigned char xx[32] = { 0x64,0x64,0x64,0x32,0x63,0x39,0x64,0x61,0x62,0x64,0x38,0x35,0x66,0x34,0x34,0x66,0x30,0x33,0x35,0x36,0x61,0x33,0x61,0x64,0x39,0x66,0x65,0x33,0x64,0x64,0x62,0x62 };
    sqlite3* db=nullptr;
    sqlite3* sql = nullptr;
    char *p=nullptr;

#  ifdef SQLITE_HAS_CODEC
    int ret = sqlite3_open("C:\\Users\\Administrator\\source\\repos\\Project1\\Project1\\nt_msg9999.db", &sql);
    printf("qq 1111ret %d\n", ret);


    ret = sqlite3_exec(sql, " PRAGMA key = 'd92a2aac87efaf8882c01c48a7738901';", nullptr, nullptr, &p);
    if (ret != SQLITE_OK)
    {
        fprintf(stderr, "sql0 erorr %s\n", p);
        sqlite3_free(p);

    }
   // sqlite3_exec(sql,"PRAGMA cipher_use_hmac = off;", nullptr, nullptr, nullptr);
   ret = sqlite3_exec(sql, "PRAGMA cipher_page_size = 4096;", nullptr, nullptr, &p);
   if (ret != SQLITE_OK)
   {
       fprintf(stderr, "sql11 erorr %s\n", p);
       sqlite3_free(p);

  }

 

   ret = sqlite3_exec(sql, "PRAGMA kdf_iter=4000;", nullptr, nullptr, &p);
   if (ret != SQLITE_OK)
   {
       fprintf(stderr, "sql erorr %s\n", p);
       //sqlite3_free(p);

   }
    ret = sqlite3_exec(sql, "PRAGMA cipher_hmac_algorithm = HMAC_SHA1;", nullptr, nullptr, &p);
    if (ret != SQLITE_OK)
    {
        fprintf(stderr, "sql2 erorr %s\n", p);
        //sqlite3_free(p);

    }
    ret = sqlite3_exec(sql, "PRAGMA cipher_default_kdf_algorithm = PBKDF2_HMAC_SHA512;", nullptr, nullptr, &p);
    if (ret != SQLITE_OK)
    {
        fprintf(stderr, "sql3 erorr %s\n", p);
        //sqlite3_free(p);

    }

    ret = sqlite3_exec(sql, "PRAGMA cipher = 'aes-256-cbc';", nullptr, nullptr, &p);
    if (ret != SQLITE_OK)
    {
        fprintf(stderr, "sql3 erorr %s\n", p);
        //sqlite3_free(p);

    }

    std::string xxx = "'C:\\Users\\Administrator\\source\\repos\\Project1\\Project1\\xxx9999-new.db'";
    std::string xxx2 = " AS wxdecrypted KEY '';";
    std::string xxx1 ="ATTACH DATABASE "+xxx+xxx2;
    printf("%s\n", xxx1.c_str());
  
    sqlite3_exec(sql, xxx1.c_str(), nullptr, nullptr, nullptr);
    if (ret != SQLITE_OK)
    {
        fprintf(stderr, "sql10 erorr %s\n", p);
        sqlite3_free(p);

    }

    sqlite3_exec(sql, "SELECT sqlcipher_export('wxdecrypted');", nullptr, nullptr, nullptr);
    if (ret != SQLITE_OK)
    {
        fprintf(stderr, "sql110 erorr %s\n", p);
        sqlite3_free(p);

    }
    sqlite3_exec(sql, "DETACH DATABASE wxdecrypted;", nullptr, nullptr, nullptr);
    if (ret != SQLITE_OK)
    {
        fprintf(stderr, "sq11l0 erorr %s\n", p);
        sqlite3_free(p);

    }
    sqlite3_close(sql);

#endif

}


