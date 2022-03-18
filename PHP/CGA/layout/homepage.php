<?php include('server.php') ?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" type="text/css" href="style.css" />
    <title>Admin Home</title>
</head>

<body>
    <div class="header">

    </div>

    <div class="container-main">

        <div class="col-left">
            <h1>Sample</h1>
        </div>

        <div class="col-right">

            <!-- logged in user information -->
            <?php if (isset($_SESSION['username'])) : ?>
                <p>Welcome <strong><?php echo $_SESSION['username']; ?></strong></p>
            <?php endif ?>

            <div class="content-main">

            </div>
        </div>

    </div>

</body>

</html>