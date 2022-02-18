<?php

include "db.php";

function showAllData()
{
    global $connection;
    $query = "SELECT * FROM users";

    $result = mysqli_query($connection, $query);
    if (!$result) {
        die("FAILED QUERY" . mysqli_error($connection));
    }

    while ($row = mysqli_fetch_assoc($result)) {
        $id = $row['id'];
        echo "<option value='$id'>$id</option>";
    }
}

function readRows()
{
    global $connection;
    $query = "SELECT * FROM users";

    $result = mysqli_query($connection, $query);

    if (!$result) {
        die("FAILED QUERY" . mysqli_error($connection));
    }

    while ($row = mysqli_fetch_assoc($result)) {
        print_r($row);
    };
}

function createRows()
{
    if (isset($_POST['submit'])) {

        global $connection;
        $username = $_POST['username'];
        $password = $_POST['password'];

        $query = "INSERT INTO users(username, password) 
                VALUES ('$username','$password')";

        $result = mysqli_query($connection, $query);
        if (!$result) {
            die("FAILED QUERY" . mysqli_error($connection));
        } else {
            echo "Record created";
        }
    }
}


function updateRows()
{
    if (isset($_POST['submit'])) {

        global $connection;

        $username = $_POST['username'];
        $password = $_POST['password'];
        $id = $_POST['id'];

        $query = "UPDATE users 
        SET username = '$username', password = '$password' 
        WHERE id = $id";

        $result = mysqli_query($connection, $query);
        if (!$result) {
            die("FAILED QUERY" . mysqli_error($connection));
        } else {
            echo "Record updated";
        }
    }
}


function deleteRows()
{
    if (isset($_POST['submit'])) {
        global $connection;

        $id = $_POST['id'];

        $query = "DELETE FROM users WHERE id = $id";

        $result = mysqli_query($connection, $query);
        if (!$result) {
            die("FAILED QUERY" . mysqli_error($connection));
        } else {
            echo "Record deleted";
        }
    }
}
