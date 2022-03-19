<?php
session_start();

// initializing variables
$first_name = $last_name = $dob = $email = $username = $password = $password_1 = $password_2 = $role = "";
$errors = array();

// connect to the database
include('db.php');

if (isset($_POST['reg_user'])) {

    // REGISTER USER

    // receive all input values from the form
    $first_name = mysqli_real_escape_string($conn, $_POST['firstname']);
    $last_name = mysqli_real_escape_string($conn, $_POST['lastname']);
    $dob = mysqli_real_escape_string($conn, $_POST['dob']);
    $email = mysqli_real_escape_string($conn, $_POST['email']);
    $username = mysqli_real_escape_string($conn, $_POST['username']);
    $password_1 = mysqli_real_escape_string($conn, $_POST['password_1']);
    $password_2 = mysqli_real_escape_string($conn, $_POST['password_2']);
    $role = mysqli_real_escape_string($conn, $_POST['role']);

    // form validation: ensure that the form is correctly filled ...
    // by adding (array_push()) corresponding error unto $errors array
    if (empty($first_name)) {
        array_push($errors, "First Name is required");
    }
    if (empty($last_name)) {
        array_push($errors, "First Name is required");
    }
    if (empty($dob)) {
        array_push($errors, "Date of Birth is required");
    }
    if (empty($email)) {
        array_push($errors, "Email is required");
    }
    if (empty($username)) {
        array_push($errors, "Username is required");
    }
    if (empty($password_1)) {
        array_push($errors, "Password is required");
    }
    if ($password_1 != $password_2) {
        array_push($errors, "The two passwords do not match");
    }
    if (empty($role)) {
        array_push($errors, "Role is required");
    }

    // first check the database to make sure 
    // a user does not already exist with the same username and/or email
    $user_check_query = "SELECT * FROM users WHERE username='$username' OR email='$email' LIMIT 1";
    $results = mysqli_query($conn, $user_check_query);
    $user = mysqli_fetch_assoc($results);

    if ($user) { // if user exists
        if ($user['username'] === $username) {
            array_push($errors, "Username already exists");
        }

        if ($user['email'] === $email) {
            array_push($errors, "Email already exists");
        }
    }

    // Finally, register user if there are no errors in the form
    if (count($errors) == 0) {
        $password = $password_1;
        //$password = md5($password_1); //encrypt the password before saving in the database

        $query = "INSERT INTO users (first_name, last_name, dob, email, username, password, created_on, is_first_login, role_id) 
            VALUES('$first_name', '$last_name', '$dob', '$email', '$username', '$password', CURRENT_TIMESTAMP, 1, '$role');";
        mysqli_query($conn, $query);
        $_SESSION['username'] = $username;
        $_SESSION['success'] = "You are now logged in";
        header('location: index.php');
    }
}

if (isset($_POST['login_user'])) {

    // LOGIN USER
    $username = mysqli_real_escape_string($conn, $_POST['username']);
    $password = mysqli_real_escape_string($conn, $_POST['password']);

    if (empty($username)) {
        array_push($errors, "Username is required");
    }
    if (empty($password)) {
        array_push($errors, "Password is required");
    }

    if (count($errors) == 0) {
        //$password = md5($password);
        $query = "SELECT * FROM users WHERE username='$username' AND password='$password'";
        $results = mysqli_query($conn, $query);

        if (mysqli_num_rows($results) == 1) {

            $_SESSION['username'] = $username;

            $row = mysqli_fetch_assoc($results);
            $roles = get_role_array($row['role_id']);
            $role_name = $roles['role_name'];

            $_SESSION['role'] = $role_name;
            if ($role_name === 'Admin') {
                $_SESSION['success'] = "You are now logged in as " . $role_name;
                header('location: admin.php');
            }
            if ($role_name === 'Professor') {
                $_SESSION['success'] = "You are now logged in as " . $role_name;
                header('location: index.php');
            }
        } else {
            array_push($errors, "Wrong username/password combination");
        }
    }
}

// return user array from their id
function get_user_array($username)
{
    global $conn;
    $query = "SELECT * FROM users WHERE username=" . $username;
    $results = mysqli_query($conn, $query);
    $users = mysqli_fetch_assoc($results);
    return $users;
}

// return user array from their id
function get_role_array($role_id)
{
    global $conn;
    $query = "SELECT * FROM roles WHERE role_id=" . $role_id;
    $results = mysqli_query($conn, $query);
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
