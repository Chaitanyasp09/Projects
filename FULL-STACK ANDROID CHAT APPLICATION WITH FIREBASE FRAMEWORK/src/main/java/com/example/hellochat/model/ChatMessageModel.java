package com.example.hellochat.model;

import android.annotation.SuppressLint;

import com.google.firebase.Timestamp;

import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.TimeZone;

public class ChatMessageModel {
    private String message;
    private String senderId;
    private Timestamp timestamp;

    public ChatMessageModel() {
    }

    public ChatMessageModel(String message, String senderId, Timestamp timestamp) {
        this.message = message;
        this.senderId = senderId;
        this.timestamp = timestamp;
    }

    public String getMessage() {
        return message;
    }

    public void setMessage(String message) {
        this.message = message;
    }

    public String getSenderId() {
        return senderId;
    }

    public void setSenderId(String senderId) {
        this.senderId = senderId;
    }

    public Timestamp getTimestamp() {
        return timestamp;
    }

    public void setTimestamp(Timestamp timestamp) {
        this.timestamp = timestamp;
    }

    // Method to get the timestamp in IST and 12-hour format
    public String getTimestampInIST() {
        if (timestamp == null) {
            return null;
        }
        Date date = timestamp.toDate();
        @SuppressLint("SimpleDateFormat") SimpleDateFormat sdf = new SimpleDateFormat("hh:mm a"); // 12-hour format with AM/PM
        sdf.setTimeZone(TimeZone.getTimeZone("Asia/Kolkata")); // Set to IST time zone
        return sdf.format(date);
    }
}
