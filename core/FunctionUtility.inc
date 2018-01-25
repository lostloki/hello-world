<?php

/**
 * FunctionUtility.
 *
 */
class FunctionUtility
{

	/**
	 * ランダム文字列生成
	 * @param  integer $length 文字列長 default:8 (1-256)
	 * @param  string  $mode   モード    default:'alnum'
	 * @return string  $sRes   ランダム文字列
	 */
	public function CreateRandomKey($length = 8, $mode = 'alnum') 
	{

		if ($length < 1 || $length > 256) {
			return false;
		}
		$smallAlphabet = 'abcdefghijklmnopqrstuvwxyz';
		$largeAlphabet = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ';
		$numeric       = '0123456789';

		switch ($mode) {
			// 小文字英字
			case 'small':
				$chars = $smallAlphabet;
				break;
			// 大文字英字
			case 'large':
				$chars = $largeAlphabet;
				break;
			// 小文字英数字
			case 'smallalnum':
				$chars = $smallAlphabet . $numeric;
				break;
			// 大文字英数字
			case 'largealnum':
				$chars = $largeAlphabet . $numeric;
				break;
			// 数字
			case 'num':
				$chars = $numeric;
				break;
			// 大小文字英字
			case 'alphabet':
				$chars = $smallAlphabet . $largeAlphabet;
				break;
			// 大小文字英数字
			case 'alnum':
			default:
				$chars = $smallAlphabet . $largeAlphabet . $numeric;
				break;
		}

		$charsLength = strlen($chars);
		$sRes = '';
		for ($i = 0; $i < $length; $i++) {
			$num = mt_rand(0, $charsLength - 1);
			$sRes .= $chars{$num};
		}
		return $sRes;

	}

	/**
	 * 画像を指定のサイズ収まる様にリサイズする
	 */
	public function getUniqSerial() {
		return urlencode(uniqid(md5(rand())));
	}

	/**
	 * ユニークな番号を取得する
	 * @param  string  $strImagePath
	 * @param  string  $intWidth
	 * @param  string  $intHeight
	 * @return 
	 */
	public function resizeImage($strImagePath, $intWidth, $intHeight = 0){
		// 第一引数のみの場合は正方形に加工する
		$intHeight = ($intHeight === 0) ? $intWidth : $intHeight;
	
		$imagick = initImage($strImagePath, $intWidth, $intHeight);
	
		// 短辺に合わせて拡縮
		$imagick->resizeImage($intWidth, $intHeight, imagick::FILTER_LANCZOS, 1, true);
	
		return $imagick->getImageBlob();
	}

	/**
	 * ユーザーエジェント取得
	 * @return string  ユーザーエジェント情報
	 */
	public function GetUA()
	{
		$ua = $_SERVER['HTTP_USER_AGENT'];
		return $ua;
	}

	/**
	 * 日付フォーマット変換処理
	 * @return string  変換後の日付
	 */
	function FormatDateTextYmdHisl($date,$fflag=null)
	{
		if ($fflag == 1){
			return (empty($date))  ?  '----/--/-- --:--' : date('Y/m/d H:i',strtotime($date));
		}else{
			return (empty($date))  ?  '' : date('Y/m/d H:i',strtotime($date));
		}
	}

	/**
	 * 日付フォーマット変換処理
	 * @return string  変換後の日付
	 */
	function FormatDateTextYmdHis2($date)
	{
		return (empty($date))  ?  '' : date('Y/m/d',strtotime($date)) .'(' .$this->week_name_jp($date) .')' .date('H:i',strtotime($date));
	}

	/**
	 * 曜日取得
	 * @return string  日本語の曜日
	 */
	public function week_name_jp($date, $bln_long = false)
	{
		$aryWeekName = array("日", "月", "火", "水", "木", "金", "土");
		$w = date("w", strtotime($date));
	
		return $aryWeekName[$w] . ($bln_long? '曜日': '');
	}

}
