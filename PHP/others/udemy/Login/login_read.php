<?php
// CRUD - Create Read Update Delete
include "db.php";
include "functions.php";
?>

<?php include "./includes/header.php"; ?>

<div class="container">
    <h1 class="text-center mt-3">Read</h1>
    <div class="mb-3">
        <pre>
            <?php
            readRows();
            ?>
        </pre>
    </div>
</div>

<?php include "./includes/footer.php"; ?>