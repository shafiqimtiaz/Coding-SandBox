<?php
// Initialize the session
session_start();

// Check if the user is logged in, if not then redirect him to login page
if (!isset($_SESSION["loggedin"]) || $_SESSION["loggedin"] !== true) {
    header("location: login.php");
    exit;
}
?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="../styles/style.css">
    <title>Admin</title>
</head>

<body>

    <header>
        <h1>Admin</h1>
        <nav>
            <p>Welcome <b><?= $_SESSION['username'] ?></b></p>
            <ul>
                <li><a href="#">Change Email</a></li>
                <li><a href="#">Change Password</a></li>
                <li><a href="../logout.php">Logout</a></li>
            </ul>
        </nav>
    </header>

    <main>

        <div class="main-body">
            <section class="col-left">
                <div class="user-info">
                    <p>Role: <?= $_SESSION['role_name'] ?></p>
                    <p>Course: N/A</p>
                    <p>Section: N/A</p>
                </div>
                <hr>
                <div class="main-menu">
                    <h3>Manage</h3>
                    <ul class="menu-list">
                        <li><a href="#">Users</a></li>
                        <li><a href="#">Professors</a></li>
                        <li><a href="#">Teaching Assistants</a></li>
                        <li><a href="#">Students</a></li>
                        <li><a href="#">Courses</a></li>
                        <li><a href="#">Sections</a></li>
                        <li><a href="#">Groups</a></li>
                        <li><a href="#">Announcements</a></li>
                        <li><a href="#">Discussions</a></li>
                        <li><a href="#">Comments</a></li>
                        <li><a href="#">Files</a></li>
                    </ul>
                </div>
            </section>

            <section class="col-right">
                <div class="content-body">
                    <p>Users</p>
                    <table>
                        <thead>
                            <tr>
                                <th>Countries</th>
                                <th>Capitals</th>
                                <th>Population</th>
                                <th>Language</th>
                            </tr>
                        </thead>
                        <tbody>
                            <tr>
                                <td>USA</td>
                                <td>Washington, D.C.</td>
                                <td>309 million</td>
                                <td>English</td>
                            </tr>
                            <tr>
                                <td>Sweden</td>
                                <td>Stockholm</td>
                                <td>9 million</td>
                                <td>Swedish</td>
                            </tr>
                        </tbody>
                    </table>
                </div>

            </section>
        </div>


    </main>

</body>

</html>