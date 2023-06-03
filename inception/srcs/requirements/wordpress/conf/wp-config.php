<?php
	define("DB_NAME",				getenv("MARIADB_NAME"));
	define("DB_USER",				getenv("MARIADB_USER"));
	define("DB_PASSWORD",			getenv("MARIADB_PASSWORD"));
	define("DB_HOST",				getenv("MARIADB_HOST") . ":3306");
	define("DB_CHARSET",			getenv("MARIADB_CHARSET"));
	define("DB_COLLATE",			getenv("MARIADB_COLLATE"));

	define('AUTH_KEY',         '+;Km7PI~,[[S.8)B)*@8z>KzoA1m+,KqV]duY:e--(]Mqb:|&x|E5FKQiOYbp*F4');
	define('SECURE_AUTH_KEY',  '&rw,[/H-]x=EIGtsrVwy|P|V7pQ^7*eOh2w=97-u|s2G>9~B,,u<w_S2D:cE~OT/');
	define('LOGGED_IN_KEY',    'N0hghvNLK-0p5wS)_bp2B=7CcA1n)[ecEUyKk}MU.fs.JW/L7fmZ-/Rxe|nVK&pP');
	define('NONCE_KEY',        '<`^t-<6#i#drX8yr[m&GPK J$m?j(&TD6|[SzwPsyYBAHbHE_$`hqOv.Gd-5<^Lc');
	define('AUTH_SALT',        'l<T| 0?po~x;KS;KfXc-Ud:<M64RA<*O.JhR870c-*22T&5,IYnmKkmif`]c&:(4');
	define('SECURE_AUTH_SALT', '67?IWvn[SP|G$VCm1fxuS]qG_&x@A{KPu!V`*as<RVT9|*IwF4U?%ar}c>zy#9Mb');
	define('LOGGED_IN_SALT',   '%t|FIH^/uB|DvV.u>m36CH/P9us*PK67-EB 3K(<a@#boc_.ewIqoA]FsUUVsJmi');
	define('NONCE_SALT',       'qdjLE~@^3;DNT={+Sat|U3Ho::S0}6&zbMd7;)>gH43jzXN9tr>=x#^!d2?jl-7%');
	define("CONCATENATE_SCRIPTS",	false);

	$table_prefix =					getenv("MARIADB_PREFIX");

	define("WP_DEBUG", true);
	if (!defined("ABSPATH"))
		define("ABSPATH", __DIR__ . "/");

	require_once ABSPATH . "wp-settings.php";