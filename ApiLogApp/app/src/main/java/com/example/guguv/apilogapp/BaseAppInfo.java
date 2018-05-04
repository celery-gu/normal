package com.example.guguv.apilogapp;

/**
 * Created by guguv on 2018/1/4.
 */

public class BaseAppInfo {
    public static final String BASE_SOURCEDIR="sourcedir";
    public static final String BASE_METHOD="method";
    public static final String BASE_PACKAGENAME="packagename";

    public String sourcedir;
    public String method;
    public String packagename;
    public String time;

    BaseAppInfo(String packagename,String sourcedir,String method){
        this.packagename=packagename;
        this.sourcedir=sourcedir;
        this.method=method;
    }
}
