package com.shihabmahamud.jdbchelloworld.cp;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import java.sql.SQLException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.stream.IntStream;

public class App {
    private static final Logger LOGGER = LoggerFactory.getLogger(App.class);
    public static void main(String[] args) {
        ExecutorService executorService = Executors.newFixedThreadPool(25);
        IntStream
                .range(0, 200)
                .forEach(iteration -> executorService
                        .submit(() -> executeCountQuery(iteration + 1)));
    }

    private static void executeCountQuery(int i) {
        LOGGER.info("Iteration: {}", i);
        var sql = "SELECT COUNT(*) FROM product";
        try (var c = DataSource.getConnection();
            var ps = c.prepareStatement(sql))
        {
          var res = ps.executeQuery();
          if (res.next()) {
              var count = res.getLong(1);
              LOGGER.info("Total row in product table: {}", count);
          }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }
}
