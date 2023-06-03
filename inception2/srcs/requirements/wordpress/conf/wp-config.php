<?php
	define("DB_NAME",				getenv("MARIADB_NAME"));
	define("DB_USER",				getenv("MARIADB_USER"));
	define("DB_PASSWORD",			getenv("MARIADB_PASSWORD"));
	define("DB_HOST",				getenv("MARIADB_HOST") . ":3306");
	define("DB_CHARSET",			getenv("MARIADB_CHARSET"));
	define("DB_COLLATE",			getenv("MARIADB_COLLATE"));

	define('AUTH_KEY',         '0>aW=7694_a4a#?QxMN9H4d8+yb+4,4d^v-UYW.,@|Xnw$e0j+G A1^}=z`=&k*,');
	define('SECURE_AUTH_KEY',  'iV_V 5{.KZ>.}<S!^g!bZ4?8JC7wFLrgC;-d7Rkc)}2qvL)`1q-}sZp5+[Wla~P]');
	define('LOGGED_IN_KEY',    '|bOn`o]RTpB.]Att)H-NfyuW-FEY23t1BB}u;qL`W:k*5Y.fSChE1gVwkY _U^I7');
	define('NONCE_KEY',        '}wae]mw4/^C2clr/XS6wHQyTkshh`mg+3rS {8zc4d01B}@8S;M-G@d]-Qoz1~oP');
	define('AUTH_SALT',        '(}sRDv>q</?`,OX[+CF:q2&uSQu78{1sa1_{Gu(xcJ@r46ix)eGX11meZ2.T1V>j');
	define('SECURE_AUTH_SALT', '&/|43E8+%R/+-O?dmwI@Ol7ba0qUco%62et(<}&-L.]-G63@lhoo&f-[s +TfWF0');
	define('LOGGED_IN_SALT',   '7?<K$4-QUwH)1F:p-!l< KlReeM&^^>5oiaETs5(F^G)tWh+ZjG?</5OR([5jvO^');
	define('NONCE_SALT',       'KP5^(P,mMD0&f<y~%O>Qrmb0ISEQ8CM&E~jTl:yL`j9{]|I@*fiqih*[g(G^-i/r');
	define("CONCATENATE_SCRIPTS",	false);

	$table_prefix =					getenv("MARIADB_PREFIX");

	define("WP_DEBUG", true);
	define( 'WP_DEBUG_DISPLAY', true );
	if (!defined("ABSPATH"))
		define("ABSPATH", __DIR__ . "/");

	require_once ABSPATH . "wp-settings.php";