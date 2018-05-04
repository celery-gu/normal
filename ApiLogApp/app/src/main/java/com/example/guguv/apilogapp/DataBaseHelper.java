package com.example.guguv.apilogapp;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

/**
 * Created by guguv on 2018/1/4.
 */

public class DataBaseHelper extends SQLiteOpenHelper{
    private static final String DB_NAME="appLogapp.db";
    static final String TABLE_NAME="appList";
    private static final int DB_VERSION=1;
    public DataBaseHelper(Context context){
        super(context,DB_NAME,null,DB_VERSION);
    }

    @Override
    public void onCreate(SQLiteDatabase db){
        String CREATE_TABLE_APP="CREATE TABLE "+TABLE_NAME+"("
                +"_id integer primary key ,"
                +BaseAppInfo.BASE_PACKAGENAME+" TEXT,"
                +BaseAppInfo.BASE_SOURCEDIR+" TEXT,"
                +BaseAppInfo.BASE_METHOD+" TEXT"
                +"createtime TimeStamp DEFAULT(datetime('now', 'localtime')))";
        db.execSQL(CREATE_TABLE_APP);
    }

    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
        db.execSQL("DROP TABLE IF EXISTS "+ TABLE_NAME);
        onCreate(db);
    }
}
