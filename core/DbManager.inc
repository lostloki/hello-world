<?php

/**
 * DbManager.
 *
 */
class DbManager {
	protected $pdo;

	/**
	 * データベースへ接続
	 *
	 * @param array $params
	 */
	public function connect() {

		// exc用
		$params = array (
				'dsn' => 'mysql:host=localhost;dbname=best_exc;charset=utf8',
				'user' => 'best_exc',
				'password' => 'exc-3ace',
				'options' => array ()
		);

		// 3ace用
		// $params = array(
		// 'dsn' => 'mysql:host=localhost;dbname=best;charset=utf8',
		// 'user' => 'root',
		// 'password' => 'threeace',
		// 'options' => array(),
		// );

		$pdo = new PDO ( $params ['dsn'], $params ['user'], $params ['password'], $params ['options'] );

		$pdo->setAttribute ( PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION );

		$this->pdo = $pdo;
	}

	/**
	 * デストラクタ
	 * データベースの接続を破棄する
	 */
	public function __destruct() {
		unset ( $this->pdo );
	}

	/**
	 * コネクションを取得
	 *
	 * @return PDO
	 */
	public function getConnection() {
		return $this->pdo;
	}

	/**
	 * トランザクション開始
	 */
	public function beginTransaction() {
		$this->pdo->beginTransaction ();
	}
	public function commit() {
		$this->pdo->commit ();
	}
	public function rollBack() {
		$this->pdo->rollBack ();
	}
}
