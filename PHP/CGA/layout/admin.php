<?php include('server.php') ?>

<!DOCTYPE html>
<html lang="en">

<head>
  <meta charset="UTF-8" />
  <meta http-equiv="X-UA-Compatible" content="IE=edge" />
  <meta name="viewport" content="width=device-width, initial-scale=1.0" />
  <link rel="stylesheet" type="text/css" href="style.css" />
  <title>Home</title>
</head>

<body>

  <div class="header">
    <h1>Admin</h1>

    <div class="nav">
      <a href="#">Home</a>
      <br><br>
      <a href="#">Switch Roles</a>
      <br><br>
      <a href="#">Change Password</a>
      <br><br>
      <a href="#">Logout</a>
    </div>

  </div>

  <div class="container-main">
    <div class="col-left">

      <h2>Main Menu</h2>

      <a href="#">Users</a>
      <br><br>
      <a href="#">Courses</a>
      <br><br>
      <a href="#">Course Sections</a>

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