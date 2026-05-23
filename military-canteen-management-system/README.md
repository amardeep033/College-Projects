# Military Canteen Management System

Military Canteen Management System is a PHP and MySQL mini-project for managing canteen inventory, employees, customers, sales, and stock reports through a browser-based admin interface.

## Features

- Admin login and dashboard
- Inventory add, update, view, and delete operations
- Employee add, update, view, and delete operations
- Customer add, update, view, and delete operations
- Point-of-sale and sales item views
- Sales and stock reporting

## Tech Stack

- PHP
- MySQL
- HTML/CSS
- XAMPP or any equivalent Apache + MySQL local stack

## Project Structure

- `mainpage.php`: login page and project entry point
- `adminmainpage.php`: admin dashboard
- `config.php`: database connection
- `canteen.sql`: database schema and seed data
- `*-add.php`, `*-update.php`, `*-view.php`, `*-delete.php`: CRUD screens
- `salesreport.php`, `stockreport.php`: reporting pages

## Local Setup

1. Install XAMPP or another local Apache/MySQL environment.
2. Copy this project folder into your web server document root, such as `htdocs`.
3. Start Apache and MySQL.
4. Create a MySQL database named `canteen`.
5. Import `canteen.sql` into that database.
6. Update the connection values in `config.php` if your local MySQL username, password, or database name differ from the defaults.
7. Open `http://localhost/military-canteen-management-system/mainpage.php` in your browser.

The default database connection in `config.php` expects:

- Host: `localhost`
- Username: `root`
- Password: empty
- Database: `canteen`

## Notes

- This repository includes a `REPORT/` directory and ER/relational model assets for the academic project deliverables.
- A few file names still use `pharm` prefixes from an earlier codebase iteration, but they are part of this canteen management project.

## Authors

- Abhiuday
- Amardeep
