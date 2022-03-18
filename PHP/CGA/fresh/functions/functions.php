<?php

$errors = array();

// return user array from their id
function get_user_array($username)
{
    global $db;
    $query = "SELECT * FROM users WHERE username=" . $username;
    $results = mysqli_query($db, $query);
    $users = mysqli_fetch_assoc($results);
    return $users;
}

// return user array from their id
function get_role_array($role_id)
{
    global $db;
    $query = "SELECT * FROM roles WHERE role_id=" . $role_id;
    $results = mysqli_query($db, $query);
    $roles = mysqli_fetch_assoc($results);
    return $roles;
}

function display_error()
{
    global $errors;
    if (count($errors) > 0) {
        echo '<div class="error">';
        foreach ($errors as $error) {
            echo $error . '<br>';
        }
        echo '</div>';
    }
}
