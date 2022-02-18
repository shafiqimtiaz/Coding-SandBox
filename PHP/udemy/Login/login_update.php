<?php
// CRUD - Create Read Update Delete
include "db.php";
include "functions.php";
updateRows();
?>

<?php include "./includes/header.php"; ?>

<div class="container">
    <h1 class="text-center mt-3">Update</h1>
    <form action="login_update.php" method="post">
        <div class="mb-3">
            <label for="username" class="form-label">Username</label>
            <input type="text" name="username" class="form-control">
        </div>
        <div class="mb-3">
            <label for="password" class="form-label">Password</label>
            <input type="password" name="password" class="form-control">
        </div>
        <div class="col-2 mb-3">
            <select name="id" id="id" class="form-select">
                <?php
                showAllData();
                ?>
            </select>
        </div>
        <button type="submit" name="submit" class="btn btn-primary">Update</button>
    </form>
</div>

<?php include "./includes/footer.php"; ?>