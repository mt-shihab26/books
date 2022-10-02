package service

import org.slf4j.LoggerFactory
import java.io.IOException
import java.nio.file.Files
import java.nio.file.Path
import java.util.function.Consumer

class FileService {
    fun readFile(path: String?) {
        LOGGER.debug("reading file from : {}", path)
        try {
            Files.readAllLines(path?.let { Path.of(it) })
                    .forEach(Consumer { line: String? -> LOGGER.info("Line: {}", line) })
        } catch (e: IOException) {
            LOGGER.error("Unable to read file from: {}", path, e)
        }
    }

    companion object {
        private val LOGGER = LoggerFactory.getLogger(FileService::class.java)
    }
}