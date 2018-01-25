<?php
class ClassLoader {
	protected $dirs;
	
	/**
	 * オートローダークラスを登録する
	 * この関数に設定したコールバックが、オートロード時に呼び出される
	 */
	public function register() {
		// loadClassを指定する
		spl_autoload_register ( array (
				$this,
				'loadClass' 
		) );
	}
	
	/**
	 * 読み込むディレクトリを設定する
	 * 
	 * @param $dir loadClassで読み込むディレクトリを引数に渡します
	 */
	public function registerDir($dir) {
		$this->dirs [] = $dir;
	}
	
	/**
	 * $dirsに設定されているディレクトリを対象に
	 * 引数で指定したクラスを読み込みます
	 * 
	 * @param $class 読み込みたいクラスを渡します
	 */
	public function loadClass($class) {
		foreach ( $this->dirs as $dir ) {
			$filename = $dir . '/' . $class . '.php';
			$filename2 = $dir . '/' . $class . '.inc';
			if (is_readable ( $filename )) {
				require $filename;
				return;
			}
			if (is_readable ( $filename2 )) {
				require $filename2;
				return;
			}
		}
	}
}
