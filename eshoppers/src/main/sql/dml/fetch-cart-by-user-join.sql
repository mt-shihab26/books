SELECT c.*
FROM cart c
        INNER JOIN user u ON (c.user_id = u.id)
WHERE u.id = ?
ORDER BY c.id DESC LIMIT 1;
