# Full-Stack Android Chat Application with Firebase Framework

## Table of Contents
- [Project Overview](#project-overview)
- [Components Used](#components-used)
- [Working Environment](#working-environment)
- [Application Architecture](#application-architecture)
- [Key Features](#key-features)
- [Screenshots](#screenshots)
- [Conclusion](#conclusion)

## Project Overview
The Full-Stack Android Chat Application with Firebase Framework is designed to facilitate real-time communication between users. Leveraging Firebase for backend services, the application supports functionalities such as user authentication, message storage, and notifications. This project aims to provide a seamless and user-friendly chat experience, making it an ideal choice for social networking or customer support systems.

## Components Used
- **Android Studio:** The primary IDE used for developing the Android application.
- **Firebase Authentication:** Handles user sign-up, login, and authentication using email/password or Google Sign-In.
- **Firebase Firestore:** A cloud-based NoSQL database used to store chat messages and user data.
- **Firebase Cloud Messaging (FCM):** Used for sending push notifications to users about new messages or updates.
- **Material Design:** For a clean and modern user interface, following Google's design guidelines.

## Working Environment
- **IDE:** Android Studio, used for developing and testing the Android application.
- **Firebase Console:** For configuring Firebase services such as Authentication, Firestore, and FCM.
- **Testing Tools:** Android Emulator and physical devices for testing different Android versions and hardware.

## Application Architecture
The application follows a modular architecture, separating the concerns of UI, data handling, and business logic. It includes:
- **Model-View-ViewModel (MVVM) Pattern:** Ensures a clear separation of UI and business logic, enhancing maintainability and scalability.
- **Repository Pattern:** Manages data operations, providing a clean API for data access to the rest of the application.

## Key Features
- **User Authentication:** Secure user login and registration using Firebase Authentication.
- **Real-Time Messaging:** Instant message delivery and receipt acknowledgment using Firestore's real-time capabilities.
- **Push Notifications:** Alerts users to new messages even when the app is not actively running.
- **Media Sharing:** Allows users to send and receive images and other media files.
- **User Presence:** Shows online/offline status of users.

## Screenshots
Here are some screenshots illustrating the key features and user interface of the application.

<div style="display: flex; flex-wrap: wrap; justify-content: space-between;">
  <img src="./Images/WelcomeScreen-1" style="width: 32%;">
  <img src="./Images/WelcomeScreen-2" style="width: 32%;">
  <img src="./Images/WelcomeScreen-3" style="width: 32%;">
  <img src="./Images/WelcomeScreen-4" style="width: 32%;">
  <img src="./Images/WelcomeScreen-5" style="width: 32%;">
  <img src="./Images/WelcomeScreen-6" style="width: 32%;">
  <img src="./Images/MainPage-1" style="width: 32%;">
  <img src="./Images/MainPage-2" style="width: 32%;">
  <img src="./Images/ChatScreen" style="width: 32%;">
</div>
## Conclusion
The Full-Stack Android Chat Application with Firebase Framework is a robust and scalable solution for real-time communication needs. It demonstrates effective use of Firebase services to provide secure authentication, reliable data storage, and real-time messaging capabilities. The application is a valuable addition to any organization seeking to enhance their communication tools or provide a chat platform for users.
