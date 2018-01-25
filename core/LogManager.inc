<?php

/**
 * LogManager.
 *
 */
class LogManager
{

	public function SetErrorLog($strTitle, $strException ) 
	{
		date_default_timezone_set('Asia/Tokyo');
		$errorLogText = '';
		$errorLogText .= "------------------------------------------------------\n";
		$errorLogText .= date("Y/m/d H:i:s") . "\n";
		$errorLogText .= print_r($strException, true);
		$errorLogText .= "\n\n";

		$strFilePath = dirname( __FILE__ ) .'/tmp/log/';
		$strFileName = date('Ymd') . '_err.log';
		
		if (is_dir($strFilePath)) {
			if ( ! is_file($strFilePath . $strFileName)) {
				@touch($strFilePath . $strFileName);
				@chmod($strFilePath . $strFileName, 0644);
			}
			error_log($errorLogText, 3, $strFilePath . $strFileName);
		}

	}

}
