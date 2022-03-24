<?php

// initializing variables
$id = $title = $posted_by = $posted_on = $content = $course_id = $course_name = "";

// ADD
if (isset($_POST['announcement_add'])) {

    // receive all input values from the form
    $title = mysqli_real_escape_string($conn, $_POST['title']);
    $content = mysqli_real_escape_string($conn, $_POST['content']);
    $course_id = mysqli_real_escape_string($conn, $_POST['course_id']);

    // form validation: ensure that the form is correctly filled ...
    // by adding (array_push()) corresponding error unto $errors array
    if (empty($title)) {
        array_push($errors, "Title is required");
    }
    if (empty($content)) {
        array_push($errors, "Content is required");
    }
    if (empty($course_id)) {
        array_push($errors, "Course is required");
    }

    $user_id = $_SESSION['user_id'];

    if (count($errors) == 0) {
        $add = "INSERT INTO announcement (title, posted_by_uid, posted_on, content, course_id)
            VALUES('$title', '$user_id', CURRENT_TIMESTAMP,'$content', '$course_id')";

        if (mysqli_query($conn, $add)) {
            array_push($success, "Added successfully");
            // clear variables
            $title = $content = "";
        } else {
            array_push($errors, "Error adding: ", mysqli_error($conn));
        }
    }
}

// UPDATE
if (isset($_POST['update_announcement'])) {

    $id = mysqli_real_escape_string($conn, $_GET['update_id']);

    // receive all input values from the form
    $title = mysqli_real_escape_string($conn, $_POST['title']);
    $content = mysqli_real_escape_string($conn, $_POST['content']);
    $course_id = mysqli_real_escape_string($conn, $_POST['course_id']);

    // form validation: ensure that the form is correctly filled ...
    // by adding (array_push()) corresponding error unto $errors array
    if (empty($title)) {
        array_push($errors, "Title is required");
    }
    if (empty($content)) {
        array_push($errors, "Content is required");
    }
    if (empty($content)) {
        array_push($errors, "Course is required");
    }

    if (count($errors) == 0) {

        $update = "UPDATE announcement set title = '$title', content = '$content', course_id = '$course_id' WHERE announcement_id ='$id'";

        if (mysqli_query($conn, $update)) {
            array_push($success, "Update Successful");
            // clear variables
            $course_name = $course_number = "";
        } else {
            array_push($errors, "Error updating: " . mysqli_error($conn));
        }
    }
}

// DELETE
if (isset($_GET['delete_id'])) {
    $id = mysqli_real_escape_string($conn, $_GET['delete_id']);
    $delete = "DELETE FROM announcement WHERE announcement_id='$id'";
    if (mysqli_query($conn, $delete)) {
        array_push($success, "Delete successful");
    } else {
        array_push($errors, "Error Deleting " . mysqli_error($conn));
    }
}

?>

<div class="content-body">
    <?php
    if (isset($_GET['delete_view'])) {
        display_success();
        display_error();
    }

    $query = "SELECT a.*, u.username, c.course_name
    FROM announcement as a
    JOIN users as u
    ON a.posted_by_uid = u.user_id
    JOIN course as c
    ON c.course_id = a.course_id
    ORDER BY announcement_id DESC";
    $results = mysqli_query($conn, $query);

    ?>
    <p><b>Announcement</b></p>
    <table>
        <thead>
            <tr>
                <?php isAdmin() ? print '<th>Announcement ID</th>' : ''; ?>
                <th>Title</th>
                <th>Posted by</th>
                <th>Posted on</th>
                <th>Content</th>
                <th>Course Name</th>
                <?php isAdmin() ? print '<th colspan="2">Action</th>' : ''; ?>

            </tr>
        </thead>
        <tbody>
            <?php
            while ($announcements = mysqli_fetch_assoc($results)) {
                $id = $announcements['announcement_id'];
                $title = $announcements['title'];
                $posted_by = $announcements['username'];
                $posted_on = $announcements['posted_on'];
                $content = $announcements['content'];
                $course_id = $announcements['course_id'];
                $course_name = $announcements['course_name'];
            ?>
                <tr>
                    <?php if (isAdmin()) {
                        echo '<td>' . $id . '</td>';
                    } ?>
                    <td><?php echo $title ?></td>
                    <td><?php echo $posted_by ?></td>
                    <td><?php echo $posted_on ?></td>
                    <td><?php echo $content ?></td>
                    <td><?php echo $course_name ?></td>
                    <?php if (isAdmin()) {
                        echo '<td><a href="?page=announcements&update_view=true&update_id=' . $id . '">Update</a></td>';
                        echo '<td><a href="?page=announcements&delete_view=true&delete_id=' . $id . '">Delete</a></td>';
                    } ?>
                </tr>
            <?php
            }
            ?>
        </tbody>
    </table>

    <?php if (isAdmin()) { ?>
        <a href="?page=announcements&add_view=true">
            <button>Add Announcement</button>
        </a>

        <?php if (isset($_GET['add_view'])) { ?>
            <hr>
            <div class="form-container">
                <form class="form-body" action="" method="post">
                    <?php echo display_success(); ?>
                    <?php echo display_error(); ?>
                    <div class="form-input">
                        <p><b>Add Announcement</b></p>

                        <label>Title</label>
                        <span><input type="text" name="title"></span>
                    </div>
                    <div class="form-input">
                        <label>Content </label>
                        <br>
                        <textarea name="content"></textarea>
                    </div>

                    <div class="form-input">
                        <label for="course">Choose a Course</label>
                        <span>
                            <select id="course" name="course_id">
                                <option value="" selected hidden>Choose a Course</option>
                                <?php
                                $courses = get_table_array('course');
                                foreach ($courses as $row) {
                                    $course_id = $row['course_id'];
                                    $course_name = $row['course_name'];
                                    echo "<option name=course_id value='$course_id'>$course_name</option>";
                                }
                                ?>
                            </select>
                        </span>
                    </div>

                    <div class="form-submit">
                        <input type="submit" name="announcement_add" value="Add">
                    </div>

                </form>
            </div>

        <?php } ?>

        <?php if (isset($_GET['update_view'])) { ?>

            <?php
            $id = mysqli_real_escape_string($conn, $_GET['update_id']);
            $query = "SELECT a.*, u.username, c.course_id FROM announcement as a
            JOIN users as u
            ON a.posted_by_uid = u.user_id
            JOIN course as c
            ON a.course_id = c.course_id
            WHERE a.announcement_id='$id'";
            $results = mysqli_query($conn, $query);

            while ($row = mysqli_fetch_assoc($results)) {
                $id = $row['announcement_id'];
                $title = $row['title'];
                $content = $row['content'];
                $update_course_id = $row['course_id'];
            }
            ?>

            <hr>
            <div class="form-container">
                <form class="form-body" action="" method="post">
                    <?php echo display_success(); ?>
                    <?php echo display_error(); ?>
                    <div class="form-input">
                        <p><b>Update Announcement</b></p>
                        <label>Announcement ID</label>
                        <span><b><?= $id ?></b></span>
                    </div>
                    <div class="form-input">
                        <label>Title</label>
                        <span><input type="text" name="title" value='<?= $title ?>'></span>
                    </div>

                    <div class="form-input">
                        <label>Content </label>
                        <br>
                        <textarea name="content"><?= $content ?></textarea>
                    </div>

                    <div class="form-input">
                        <label for="course">Choose a Course</label>
                        <span>
                            <select id="course" name="course_id">
                                <?php
                                $courses = get_table_array('course');
                                foreach ($courses as $row) {
                                    $course_id = $row['course_id'];
                                    $course_name = $row['course_name'];
                                    if ($update_course_id == $course_id) {
                                        echo "<option name=course_id value='$course_id' selected>$course_name</option>";
                                    } else {
                                        echo "<option name=course_id value='$course_id'>$course_name</option>";
                                    }
                                }
                                ?>
                            </select>
                        </span>
                    </div>

                    <div class="form-submit">
                        <input type="submit" name="update_announcement" value="Update">
                    </div>
                </form>
            </div>

        <?php } ?>

    <?php } ?>

</div>