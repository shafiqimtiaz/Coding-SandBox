<?php
// CRUD - Create Read Update Delete
include "db.php";
include "functions.php";
deleteRows();
?>

<?php include "./includes/header.php"; ?>

<div class="container">
    <h1 class="text-center mt-3">Delete</h1>
    <form action="login_delete.php" method="post">
        <div class="col-2 mb-3">
            <select name="id" id="id" class="form-select">
                <?php
                showAllData();
                ?>
            </select>
        </div>
        <button type="submit" name="submit" class="btn btn-primary">Delete</button>
    </form>
</div>

<?php include "./includes/footer.php"; ?>