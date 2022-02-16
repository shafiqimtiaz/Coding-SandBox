 <?php
    //$con = mysqli_connect("localhost","UserName","Password","DatabaseName");
    $con = mysqli_connect("localhost", "root", "root.SQL", "userdetails");

    if (!$con) {
        die("Connection Error");
    } else {

        echo 'Connection Successfull';
    }

    ?>