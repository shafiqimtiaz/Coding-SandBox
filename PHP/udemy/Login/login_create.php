<?php
// CRUD - Create Read Update Delete
include "db.php";
include "functions.php";
createRows();
?>

<?php include "./includes/header.php"; ?>

<div class="container">
    <h1 class="text-center mt-3">Create</h1>
    <form action="login_create.php" method="post">
        <div class="mb-3">
            <label for="username" class="form-label">Username</label>
            <input type="text" name="username" class="form-control">
        </div>
        <div class="mb-3">
            <label for="password" class="form-label">Password</label>
            <input type="password" name="password" class="form-control">
        </div>
        <button type="submit" name="submit" class="btn btn-primary">Create</button>
    </form>
</div>

<?php include "./includes/footer.php"; ?>