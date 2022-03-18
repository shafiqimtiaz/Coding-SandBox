<?php
// Enter your host name, database username, password, and database name.
// If you have not set database password on localhost then set empty.

define('DB_SERVER', 'localhost:3306');
define('DB_USERNAME', 'root');
define('DB_PASSWORD', 'root.SQL');
define('DB_NAME', 'cga');

/* Attempt to connect to MySQL database */
$db = mysqli_connect(DB_SERVER, DB_USERNAME, DB_PASSWORD, DB_NAME);

// Check connection
if (!$db) {
    die("ERROR: Could not connect. " . mysqli_connect_error());
}
