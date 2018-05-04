package com.example.guguv.apilogapp;

import android.app.AlertDialog;
import android.app.AndroidAppHelper;
import android.content.Context;
import android.content.DialogInterface;
import android.content.pm.PackageInfo;
import android.database.Cursor;
import android.graphics.drawable.Drawable;
import android.net.Uri;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ImageView;
import android.widget.ListView;
import android.widget.TextView;
import java.util.ArrayList;
import java.util.List;

import de.robv.android.xposed.XposedBridge;

import static android.widget.AdapterView.*;
class AppInfo{
    public String appName="";
    public String packageName="";
    //public String versionName="";
    //public int versionCode=0;
    public String sourceDir="";
    public Drawable appIcon=null;
    public void print(){
        Log.v("app","Name:"+appName+" Package:"+packageName);
        //Log.v("app","Name:"+appName+" versionName:"+versionName);
        //Log.v("app","Name:"+appName+" versionCode:"+versionCode);
    }
}

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        try {
            final List<AppInfo> appLists=new ArrayList<>();
            List<PackageInfo> packages=getPackageManager().getInstalledPackages(0);
            for(int i=0;i<packages.size();++i){
                PackageInfo packageInfo=packages.get(i);
                AppInfo tmpInfo=new AppInfo();
                tmpInfo.appName=packageInfo.applicationInfo.loadLabel(getPackageManager()).toString();
                tmpInfo.packageName=packageInfo.packageName;
                tmpInfo.sourceDir=packageInfo.applicationInfo.sourceDir;
                tmpInfo.appIcon=packageInfo.applicationInfo.loadIcon(getPackageManager());
                Log.d("PackageInfo:",packageInfo.applicationInfo.sourceDir);
                if(searchApp(packageInfo.applicationInfo.sourceDir))
                    appLists.add(tmpInfo);
            }
            ListView listView=(ListView)findViewById(R.id.list);
            MyAdapter arrayAdapter=new MyAdapter(this,R.layout.list_item,appLists);
            listView.setAdapter(arrayAdapter);

            listView.setOnItemClickListener(new OnItemClickListener() {
                public void onItemClick(AdapterView<?> adapterView, View view, int i, long l){
                    AppInfo app=appLists.get(i);
                    showLog(app);
                }
            });
        }catch(Exception e){
            Log.d("error:","Can not print tmpInfo");
            e.printStackTrace();
        }
    }
    public boolean searchApp(String mSourceDir){
        final Uri uri = Uri.parse("content://com.example.guguv.apilogapp.AppProvider/appList");
        Context context=MainActivity.this;
        Cursor cursor = context.getContentResolver().query(uri, new String[]{"packagename", "sourcedir", "method"}, null, null, null);
        //Cursor cursor = context.getContentResolver().query(uri, new String[]{"packagename", "sourcedir", "method","createtime"}, null, null, null);
        Log.d("SQLite start","is starting");
        while(cursor.moveToNext()){
            BaseAppInfo mApp = new BaseAppInfo(cursor.getString(0), cursor.getString(1), cursor.getString(2));
            Log.d("SQLite main:", mApp.packagename + "-----" + mApp.sourcedir + "-----" + mApp.method);
            if(mApp.sourcedir.equals(mSourceDir))
            {
                Log.d("search_app_exist",mSourceDir+"调用了敏感api,return true");
                return true;
            }
        }
        Log.d("search_app_exist",mSourceDir+"没有调用敏感api，return false");
        return false;
    }

    public void showLog(AppInfo app){
        new AlertDialog.Builder(this).
                setTitle(app.appName)
                .setMessage(getMethod(app))
                .setPositiveButton("确定", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialogInterface, int i) {

                    }
                })
                .show();
    }
    public String getMethod(AppInfo app)
    {
        String result="";
        final Uri uri = Uri.parse("content://com.example.guguv.apilogapp.AppProvider/appList");
        Context context=MainActivity.this;
        Cursor cursor = context.getContentResolver().query(uri, new String[]{"packagename", "sourcedir", "method"}, null, null, null);
        //Cursor cursor = context.getContentResolver().query(uri, new String[]{"packagename", "sourcedir", "method","createtime"}, null, null, "creattime");
        Log.d("SQLite start","is starting");
        while(cursor.moveToNext()){
            BaseAppInfo mApp = new BaseAppInfo(cursor.getString(0), cursor.getString(1), cursor.getString(2));
            Log.d("SQLite main:", mApp.packagename + "-----" + mApp.sourcedir + "-----" + mApp.method);
            if(mApp.sourcedir.equals(app.sourceDir))
            {
                //result+=mApp.creat
                result+=mApp.method+"\n";
            }
        }
        return result;
    }

}
class MyAdapter extends ArrayAdapter<AppInfo> {
    private Context mContext;
    private int resource;
    public MyAdapter(Context context,int resource,List<AppInfo> data){
        super(context,resource,data);
        this.mContext=context;
        this.resource=resource;
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent){
        ViewHolder holder=null;
        if(convertView==null){
            holder=new ViewHolder();
            convertView= LayoutInflater.from(mContext).inflate(resource,null);
            holder.image=(ImageView)convertView.findViewById(R.id.ItemImage);
            holder.title=(TextView)convertView.findViewById(R.id.ItemTitle);
            holder.text=(TextView)convertView.findViewById(R.id.ItemText);
            convertView.setTag(holder);
        }else{
            holder=(ViewHolder)convertView.getTag();
        }

        holder.image.setImageDrawable(getItem(position).appIcon);
        holder.title.setText(getItem(position).appName);
        //holder.title.setText((String) listItem.get(position).appName);
        holder.text.setText(getItem(position).packageName);
        //holder.text.setText((String) listItem.get(position).packageName);

        return convertView;
    }

    final class ViewHolder{
        ImageView image;
        TextView title;
        TextView text;
    }
}

