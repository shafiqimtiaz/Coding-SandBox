<?php

$conn = mysqli_connect("localhost:3306", "root", "root.SQL", "");

if (!$conn) {
	echo mysqli_connect_error();
	die();
}

echo "Database connected";

// phpinfo();