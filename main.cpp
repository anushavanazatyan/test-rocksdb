#include <QCoreApplication>
#include <assert.h>
#include "rocksdb/db.h"
#include <stdio.h>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    rocksdb::DB* db;
    rocksdb::Options options;
    options.create_if_missing = true;
    rocksdb::Status status = rocksdb::DB::Open(options, "./tmp/testdb", &db);
  //  assert(status.ok());

    options.error_if_exists = true; // - rise error if db exists
    
    int bb;
    printf("everything ok ");
    scanf(" press key %d", &bb);
    std::string value = std::string(" Some Value");
    std::string key = std::string("testkey");

    rocksdb::Status sss = db->Put(rocksdb::WriteOptions(), key, value);
    if(sss.ok())
    {
        printf("successed to create and write in base");
    }
    delete db;
    return a.exec();
}
