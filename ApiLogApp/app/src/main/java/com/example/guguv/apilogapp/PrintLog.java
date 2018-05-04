package com.example.guguv.apilogapp;

import android.app.AndroidAppHelper;
import android.app.PendingIntent;
import android.content.ContentValues;
import android.content.Context;
import android.content.pm.PackageManager;
import android.database.Cursor;
import android.net.Uri;
import android.provider.ContactsContract;
import android.util.Log;


import de.robv.android.xposed.IXposedHookLoadPackage;
import de.robv.android.xposed.XC_MethodHook;
import de.robv.android.xposed.XposedBridge;
import de.robv.android.xposed.callbacks.XC_LoadPackage.LoadPackageParam;

import static de.robv.android.xposed.XposedHelpers.findAndHookMethod;
/**
 * Created by guguv on 2018/1/3.
 */

public class PrintLog implements IXposedHookLoadPackage {
    public void handleLoadPackage(final LoadPackageParam lpparam) throws Throwable {

        //XposedBridge.log("Loaded app: " + lpparam.packageName);
        //Uri uri = Uri.parse("content://com.example.guguv.apilogapp.AppProvider");
        //if(lpparam.packageName.equals("android.telephony"))
            findAndHookMethod("android.telephony.SmsManager", lpparam.classLoader, "sendTextMessage",
                String.class,
                String.class,
                String.class,
                PendingIntent.class,
                PendingIntent.class,
                new XC_MethodHook() {
                    protected void beforeHookedMethod(MethodHookParam param) throws Throwable {
                        XposedBridge.log("---------" + lpparam.appInfo.sourceDir + "----------");
                        XposedBridge.log("执行敏感函数sendTextMessage发送短信");
                        insertDB(lpparam.packageName, lpparam.appInfo.sourceDir, "sendTextMessage");
                    }
                });

        //if(lpparam.packageName.equals("android.content"))
        findAndHookMethod("android.content.ContentResolver", lpparam.classLoader, "query",
                Uri.class,
                String[].class,
                String.class,
                String[].class,
                String.class,
                new XC_MethodHook() {
                    protected void beforeHookedMethod(MethodHookParam param) throws Throwable {
                        if (param.args[0] == ContactsContract.Contacts.CONTENT_URI) {
                            XposedBridge.log("---------" + lpparam.appInfo.sourceDir + "----------");
                            XposedBridge.log("执行敏感函数query");
                            insertDB(lpparam.packageName,lpparam.appInfo.sourceDir,"query");
                        }
                    }
                });

        //if(lpparam.packageName.equals("android.telephony"))
        findAndHookMethod("android.telephony.TelephonyManager", lpparam.classLoader, "getLine1Number",
                new XC_MethodHook() {
                    protected void beforeHookedMethod(MethodHookParam param) throws Throwable {
                        XposedBridge.log("---------" + lpparam.appInfo.sourceDir + "----------");
                        XposedBridge.log("执行敏感函数getLine1Number");
                        insertDB(lpparam.packageName, lpparam.appInfo.sourceDir, "getLine1Number");
                    }
                });


        /*findAndHookMethod("android.location.LocationManager", lpparam.classLoader, "getLastKnownLocation",
                String.class,
                new XC_MethodHook() {
                    protected void beforeHookedMethod(MethodHookParam param) throws Throwable {
                        XposedBridge.log("---------" + lpparam.appInfo.sourceDir + "----------");
                        XposedBridge.log("执行敏感函数getLastKnownLocation");
                        insertDB(lpparam.packageName, lpparam.appInfo.sourceDir, "getLastKnownLocation");
                    }
                });*/
    }
    public void insertDB(String packageName, String sourceDir, String method) {
        XposedBridge.log("start insert");
        final Uri uri = Uri.parse("content://com.example.guguv.apilogapp.AppProvider/appList");
        Context context = null;
        try {
            context = ((Context) AndroidAppHelper.currentApplication()).createPackageContext("com.example.guguv.apilogapp",0);
        } catch (PackageManager.NameNotFoundException e) {
            e.printStackTrace();
        }
        ContentValues mContentValues = new ContentValues();
        mContentValues.put("packagename", packageName);
        mContentValues.put("sourcedir", sourceDir);
        mContentValues.put("method", method);
        context.getContentResolver().insert(uri, mContentValues);
        Cursor appCursor = context.getContentResolver().query(uri, new String[]{"packagename", "sourcedir", "method"}, null, null, null);
        while (appCursor.moveToNext()) {
            BaseAppInfo mApp = new BaseAppInfo(appCursor.getString(0), appCursor.getString(1), appCursor.getString(2));
            Log.d("SQLite:", mApp.packagename + "-----" + mApp.sourcedir + "-----" + mApp.method);
            XposedBridge.log("SQLite:" + mApp.packagename + "-----" + mApp.sourcedir + "-----" + mApp.method);
        }
    }
}