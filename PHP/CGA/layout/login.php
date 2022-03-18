<?php include('server.php') ?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <link rel="stylesheet" type="text/css" href="style.css" />
    <title>Login</title>
</head>

<body>
    <div class="header">
        <h1>Login</h1>
    </div>

    <div class="container-form">

        <form class="form-body" method="post" action="login.php">

            <?php echo display_error(); ?>

            <div class="input-group">
                <label>Username</label>
                <input type="text" name="username">
            </div>

            <div class="input-group">
                <label>Password</label>
                <input type="password" name="password">
            </div>

            <div class="input-group">
                <button type="submit" class="btn" name="login_user">Login</button>
                <br>
                <a href="#">Forgot password?</a>
            </div>

        </form>
    </div>
</body>

</html>