<?php

$connection = mysqli_connect('localhost:3306', 'root', 'root.SQL', 'login');

if (!$connection) {
    die("Connection failed");
}