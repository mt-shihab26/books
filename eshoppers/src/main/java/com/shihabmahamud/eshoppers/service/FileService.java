package com.shihabmahamud.eshoppers.service;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;

public class FileService {
    private static final Logger LOGGER = LoggerFactory.getLogger(FileService.class);

    public void readFile(String path) {
        LOGGER.debug("reading file from : {}", path);
        try {
            Files.readAllLines(Path.of(path))
                    .forEach(line -> LOGGER.info("Line: {}", line));
        } catch (IOException e) {
            LOGGER.error("Unable to read file from: {}", path, e);
        }
    }
}