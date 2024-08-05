package com.pu.LoginProject.service;

import com.pu.LoginProject.entity.User;

public interface UserService {

	public User saveUser(User user);

	public void removeSessionMessage();

}