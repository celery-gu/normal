package com.example.guguv.apilogapp;

import android.content.ContentProvider;
import android.content.ContentValues;
import android.content.Context;
import android.content.UriMatcher;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.net.Uri;
import android.util.Log;

/**
 * Created by guguv on 2018/1/4.
 */

public class AppProvider extends ContentProvider {
    public static final String AUTHORITY="com.example.guguv.apilogapp.AppProvider";
    public static final Uri APP_CONTENT_URI=Uri.parse("content://"+AUTHORITY+"/appList");
    private static final UriMatcher mUriMatcher=new UriMatcher(UriMatcher.NO_MATCH);
    private SQLiteDatabase mDb;
    private Context mContext;
    private String table;

    static {
        mUriMatcher.addURI(AUTHORITY,"appList",0);
    }

    @Override
    public boolean onCreate(){
        table=DataBaseHelper.TABLE_NAME;
        mContext=getContext();
        initProvoder();
        Log.d("SQLite:","create success");
        return false;
    }

    private void initProvoder(){
        mDb=new DataBaseHelper(mContext).getWritableDatabase();
        new Thread(new Runnable() {
            @Override
            public void run() {
                mDb.execSQL("DELETE FROM "+DataBaseHelper.TABLE_NAME);
            }
        }).start();
    }

    @Override
    public Cursor query(Uri uri, String[] projection, String selection, String[] selectionArgs, String sortOrder) {
        String table=DataBaseHelper.TABLE_NAME;
        Cursor mCursor = mDb.query(table, projection, selection, selectionArgs, null, sortOrder, null);
        return mCursor;
    }

    @Override
    public String getType(Uri uri){
        return null;
    }

    @Override
    public Uri insert(Uri uri, ContentValues values){
        mDb.insert(table,null,values);
        mContext.getContentResolver().notifyChange(uri,null);
        return null;
    }

    @Override
    public int delete(Uri uri, String selection, String[] selectionArgs) {
        return 0;
    }

    @Override
    public int update(Uri uri, ContentValues values, String selection, String[] selectionArgs) {
        return 0;
    }
}
