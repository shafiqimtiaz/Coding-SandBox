<?php

$query = "SELECT a.title, u.username, a.posted_on, a.content, c.course_name, cs.section_name
FROM announcement as a
JOIN users as u
ON a.posted_by_uid = u.user_id
JOIN course_section as cs
ON cs.section_id = a.section_id
JOIN course as c
ON c.course_id = cs.course_id";
$announcements = mysqli_query($conn, $query);

?>

<div class="content-body">
    <p><b>Home Page</b></p>

    <?php if (!isAdmin()) { ?>

        <div class="user-info-content">
            <hr>
            <p>User Info</p>
            <?php
            while ($row = mysqli_fetch_assoc($user_info)) {
                echo "<ul>";
                echo "<li>Course number: " . $row['course_number'] . "</li>";
                echo "<li>Course name: " . $row['course_name'] . "</li>";
                echo "<li>Section name: " . $row['section_name'] . "</li>";
                if ($_SESSION['role_name'] == 'Student') {
                    echo "<li>Group name: " . $row['group_name'] . "</li>";
                    if ($row['group_leader_sid'] == $row['student_id']) {
                        echo "<li>Group leader of " . $row['group_name'] . "</li>";
                    }
                }
                echo "</ul><br>";
            }
            ?>
        </div>
        <br>
    <?php } ?>

    <div class="announcement-content">
        <hr>
        <p>Announcements</p>
        <?php
        while ($row = mysqli_fetch_assoc($announcements)) {
            echo "<ul>";
            echo '<li> <b> Title: ' . $row['title'] . '</b> </li>';
            echo '<li> <b> Content: ' . $row['content'] . ' </b> </li>';
            echo '<li> Posted by: ' . $row['username'] . '</li>';
            echo '<li> Posted on: ' . $row['posted_on'] . '</li>';
            echo '<li> Course: ' . $row['course_name'] . '</li>';
            echo '<li> Section: ' . $row['section_name'] . '</li>';
            echo "</ul><br>";
        }
        ?>
    </div>
    <hr>
</div>