package com.pu.LoginProject.repostior;

import org.springframework.data.jpa.repository.JpaRepository;

import com.pu.LoginProject.entity.User;
public interface UserRepo extends JpaRepository<User, Integer> {

	public User findByEmail(String emaill);

}