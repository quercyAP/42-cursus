<?php
	define("DB_NAME",				getenv("MARIADB_NAME"));
	define("DB_USER",				getenv("MARIADB_USER"));
	define("DB_PASSWORD",			getenv("MARIADB_PASSWORD"));
	define("DB_HOST",				getenv("MARIADB_HOST") . ":3306");
	define("DB_CHARSET",			getenv("MARIADB_CHARSET"));
	define("DB_COLLATE",			getenv("MARIADB_COLLATE"));

	define('AUTH_KEY',         '`s-XO?9f$?HqB6]mNe)!+XjQ[b{F]lj5Hmr^Mo&>ni2z5caP8jO*6xidPx|E/rh^');
	define('SECURE_AUTH_KEY',  'RbZw(l)?oPtZK5OF_;O%X?C>u<;}Y`9<XKA]KgT&e)}LR+}|Xq+v3k5xZ~Z|3!eC');
	define('LOGGED_IN_KEY',    'qA.SH5cHx1;xu-uw|G7L`U8Nec.KP+|.lW-!._1($l%OQR-UA|soUJf7P@TDT</3');
	define('NONCE_KEY',        'HQH|5EA/&+dPILCjJHF&^IAQY=Mq^igo-NJ}vpEx;oY68Yk{E#m*D.(KSh&+51q}');
	define('AUTH_SALT',        'wYy/}o^{v}xIi^J+KqlW5XdNFNh-+7ywU_^+R)&D4&MKx<4rrvfVa3:x~cF<||.T');
	define('SECURE_AUTH_SALT', 'gQ#DW3~Gj@rg.VMF(i?*=*]KzTd0,XfqZk,#<goO-3s]-9_n#H2ggG^h*`Rz0j+a');
	define('LOGGED_IN_SALT',   'Bb{S07UWyqz2|Q3gW$l*}F=-fs]DHT~N^vJ]u7r_Op$f:rkVZx0|W7Nu,-0GOpX9');
	define('NONCE_SALT',       'F>WxcH( pU8;g}C/.#;@{ #uhgNq&1M&>y+lJkRbW8}>PhF0|W6< JC1rGN5/xnq');
	define("CONCATENATE_SCRIPTS",	false);

	$table_prefix =					getenv("MARIADB_PREFIX");

	define("WP_DEBUG", true);
	define( 'WP_DEBUG_DISPLAY', true );
	if (!defined("ABSPATH"))
		define("ABSPATH", __DIR__ . "/");

	require_once ABSPATH . "wp-settings.php";