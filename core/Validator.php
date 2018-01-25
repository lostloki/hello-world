<?php
class Validator
{
    /**
     * 未入力チェックを行う
     * @param $dto
     * @param $paramName
     * @param $errMessage
     */
    public function checkEmpty($dto,$paramName,$errMessage,$isTel = false){

        // 引数のDtoに引数のパラメータに対応したメソッドが存在するかチェック
        // 存在しない場合はプログラムミス
        $getMethodName = "get" . $paramName;
        // dtoにcolNameに該当するgetメソッドが存在するかチェックする
        if (!method_exists($dto,$getMethodName)) {
            //
            throw new Exception('checkEmptyメソッドが存在しません' . $paramName  );
            exit;
        }

        // 未入力をチェックする
        $value = $dto->$getMethodName();

        if ($isTel){
            // 電話番号の場合は-を置き換える。
            $value = str_replace("-", "", $value);
        }

        if (empty($value)) {

            $setMethodName = "set" . $paramName . "Err";
            // エラーメッセージを設定するパラメータがあるかチェック
            if (method_exists($dto,$setMethodName)) {
                // 使用したくない場合もあるかもしれないのでここは存在しなかったら
                // エラーメッセージを設定せずに終了する。
                $dto->$setMethodName($errMessage);
            }
            $dto->setIsError(true);
            return false;
        }
        return true;

    }

    /**
     * アップロードされたファイルをチェックする。
     * @param $dto
     * @param $paramName
     * @param $errMessage
     */
    public function checkFile($dto,$paramName){

        // $_FILES[$paramName]['error'] の値を確認
        if (isset($_FILES[$paramName]['error'])) {

            // 未定義である・複数ファイルである・$_FILES Corruption 攻撃を受けた
            // どれかに該当していれば不正なパラメータとして処理する
            if (! is_int($_FILES[$paramName]['error'])) {
                $message = 'パラメータが不正です。';
            } else {
                switch ($_FILES[$paramName]['error']) {
                    case UPLOAD_ERR_OK : // OK
                        break;
                    case UPLOAD_ERR_NO_FILE : // ファイル未選択
                        $message = MSG_FILE_NOTHING;
                        break;
                    case UPLOAD_ERR_FORM_SIZE : // フォーム定義の最大サイズ超過 (設定した場合のみ)
                        // <input type="hidden" name="MAX_FILE_SIZE" value="1500" />
                        $message = 'ファイルサイズが大きすぎます。';
                        break;
                    case UPLOAD_ERR_INI_SIZE : // upload_max_filesize超過
                        $message = 'ファイルサイズが大きすぎます。';
                        break;
                    default :
                        $message = 'その他のエラーが発生しました。';
                        break;
                }
            }



        }else{
            // post_max_sizeを超えた場合は$_POSTがセットされない。
            // ×このためHTML側でチェックする。⇒セキュリティ制約により取得できないらしい
            // ファイルアップロードがある場合はPOST（$_SERVER["REQUEST_METHOD"]）で
            // $_POSTが空の場合、post_max_sizeを超えていると判断する。
            if($_SERVER["REQUEST_METHOD"] == "POST" && count($_POST) == 0){
                $message = 'ファイルサイズが大きすぎます。';
            }
        }

        if (!empty($message)) {

            $setMethodName = "set" . $paramName . "Err";
            // エラーメッセージを設定するパラメータがあるかチェック
            if (method_exists($dto,$setMethodName)) {
                // 使用したくない場合もあるかもしれないのでここは存在しなかったら
                // エラーメッセージを設定せずに終了する。
                $dto->$setMethodName($message);
            }
            $dto->setIsError(true);
            return false;
        }
        return true;

    }
}
