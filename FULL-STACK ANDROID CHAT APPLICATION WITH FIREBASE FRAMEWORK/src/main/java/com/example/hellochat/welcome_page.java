package com.example.hellochat;

import android.content.Intent;
import android.os.Bundle;
import android.view.animation.AlphaAnimation;
import android.view.animation.Animation;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

public class welcome_page extends AppCompatActivity {

    private ImageView gifImageView;
    private TextView welcomeText;
    private TextView subText;
    private Button getStartedButton;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_welcome_page_new);

        gifImageView = findViewById(R.id.gifImageView);
        welcomeText = findViewById(R.id.welcomeText);
        subText = findViewById(R.id.subText);
        getStartedButton = findViewById(R.id.getStartedButton);

        // Set fade-in animation
        Animation fadeIn = new AlphaAnimation(0, 1);
        fadeIn.setDuration(1500);

        gifImageView.startAnimation(fadeIn);
        welcomeText.startAnimation(fadeIn);
        subText.startAnimation(fadeIn);
        getStartedButton.startAnimation(fadeIn);

        // Set click listener for the button
        getStartedButton.setOnClickListener(v -> {
            Intent intent = new Intent(welcome_page.this, login_PhoneNo.class);
            startActivity(intent);
            finish();
        });
    }
}