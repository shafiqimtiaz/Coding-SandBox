<?php

session_start();

$username = $password = "";

if (isset($_SESSION["loggedin"]) && $_SESSION["loggedin"] === true) {
    header("location: index.php");
    exit;
}

require_once("./configs/db.php");
include("./functions/functions.php");

$username = $password = "";

if (isset($_POST['login_user'])) {


    // Check if username is empty
    if (empty(trim($_POST["username"]))) {
        array_push($errors, "Username is required");
    } else {
        $username = mysqli_real_escape_string($db, $_POST['username']);
    }

    // Check if password is empty
    if (empty(trim($_POST["password"]))) {
        array_push($errors, "Password is required");
    } else {
        $password = mysqli_real_escape_string($db, $_POST['password']);
    }

    if (count($errors) == 0) {

        $query = "SELECT * FROM users WHERE username='$username' AND password='$password'";
        $results = mysqli_query($db, $query);

        if (mysqli_num_rows($results) == 1) {

            $_SESSION["loggedin"] = true;
            $_SESSION['username'] = $username;
            $row = mysqli_fetch_assoc($results);
            $role_id = $row['role_id'];
            $_SESSION['role_id'] = $role_id;

            if ($role_id === '1') {
                $_SESSION['role_name'] = "Admin";
                header('location: admin.php');
            }
            if ($role_name === '3') {
                $_SESSION['role_name'] = "Student";
                header('location: student.php');
            }

            header("location: ./admin/admin.php");
        } else {
            array_push($errors, "Invalid username or password");
        }
    }

    mysqli_close($db);
}

?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="./styles/style.css">
    <title>Login</title>
</head>

<body>

    <header>
        <h1>Login</h1>
    </header>

    <main>

        <div class="form-container">

            <form class="form-body" action="login.php" method="post">

                <?php echo display_error(); ?>

                <div class="form-input">
                    <label>Username</label>
                    <span>
                        <input type="text" name="username" value="<?php echo $username; ?>">
                    </span>

                </div>

                <div class="form-input">
                    <label>Password</label>
                    <span>
                        <input type="password" name="password">
                    </span>

                </div>

                <div class="form-submit">
                    <button type="submit" class="btn" name="login_user">Login</button>
                    <br><br>
                    <a href="#">Forgot password?</a>
                </div>

            </form>
        </div>

    </main>

</body>

</html>