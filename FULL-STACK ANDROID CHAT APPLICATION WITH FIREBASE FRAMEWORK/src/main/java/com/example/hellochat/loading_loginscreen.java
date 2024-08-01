package com.example.hellochat;

import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.view.View;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.view.ViewCompat;

import com.example.hellochat.utils.FirebaseUtil;

public class loading_loginscreen extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_loading_loginscreen);

        new Handler().postDelayed(new Runnable() {
            @Override
            public void run() {
                if(FirebaseUtil.isLoggedIn()){
                    startActivity(new Intent(loading_loginscreen.this,MainActivity.class));
                }else {
                startActivity(new Intent(loading_loginscreen.this,welcome_page.class));
            }
                finish();}
        },700);

    }}