package com.shihabmahamud.cdi;

import org.jboss.weld.environment.se.Weld;
import org.jboss.weld.environment.se.WeldContainer;

public class Main {
    public static void main(String[] args) {
        Weld weld = new Weld();
        try (WeldContainer container = weld.initialize()){
            UserService userService
                    = container.select(UserService.class).get();
            userService.saveUser(new User("User", "Password"));
        } catch (Exception e) {
            throw new RuntimeException("Here");
        }
    }
}