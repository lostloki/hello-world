<?php

class CoreLogic {

    private $debug_flag = 1;

    /**
     * 空白チェック
     * PHPバージョンによってemptyの引数にメソッドを指定できないため、
     * 関数化
     */
    function isEmpty($value){
        return empty($value);
    }

    /**
     * ログ出力
     */
    function outputLog($value){
        if ($this->debug_flag == 1){
             ChromePhp::log($value);
        }
    }

    /**
     * リクエストがPOSTかどうか判断する
     * @return boolean
     */
    function isPost(){
        if($_SERVER["REQUEST_METHOD"] != "POST"){
            return false;
        }

        return true;
    }

    /**
     * リクエストがGETかどうか判断する
     * @return boolean
     */
    function isGet(){
        if($_SERVER["REQUEST_METHOD"] != "GET"){
            return false;
        }

        return true;
    }


    /**
     * SQLより取得したカラム名をDTOの名称に変換する
     * 例：city_name → cityName
     */
    function convertDtoMethodName($colName){

        // _ で配列に変換する
        $words =  explode( '_', $colName);

        $methodName = "";

        // ループ
        foreach ($words as $word){
            // 先頭を大文字に変換する
            $word = ucfirst($word);
            $methodName .= $word;
        }

        return $methodName;

    }

    /**
     * constに定義されているJSONをDTOに設定して返します
     *
     * @param
     *            $key:constに定義されている配列のkey
     */
    protected function _getSortDtoList($keyName) {

        $list = json_decode($keyName,true);

        $constDtoList = array();
        foreach ( $list as $key => $value ) {
// TODO ビルドエラー解消のため、コメントアウト.
//             $sortDto = new sortDto();
            $sortDto->setName($value['name']);
            $sortDto->setCode($value['code']);
            $sortDto->setSortName($value['sort_name']);

            // dtoにメソッドが存在するかチェックする
            if (isset($value['date_flag'])) {
                $sortDto->setDateFlag($value['date_flag']);
            }

            $sortDtoList[] = $sortDto;
        }

        return $sortDtoList;

    }

    /**
     * constに定義されているJSONをDTOに設定して返します
     *
     * @param
     *            $key:constに定義されているキー
     * @param
     *            $valList:dtoに設定したいvalueのリスト
     */
    protected function _findSortDtoList($key, $codeList) {

        $list = json_decode($key,true);

        $constDtoList = array();
        foreach ( $list as $key => $value ) {
            if (array_search($value['code'],$codeList) > - 1) {
                $sortDto = new SortDTO();
                $sortDto->setName($value['name']);
                $sortDto->setCode($value['code']);
                $sortDto->setSortName($value['sort_name']);
                $sortDtoList[] = $sortDto;
            }
        }

        return $sortDtoList;

    }

    /**
     * constに定義されているJSONをDTOに設定して返します
     *
     * @param
     *            $key:constに定義されているキー
     * @param
     *            $valList:dtoに設定したいvalueのリスト
     */
    protected function _findSortList($key, $code) {

        $codeList[] = $code;

        $list = $this->_findSortDtoList($key, $codeList);

        if (count($list) == 0){
            return null;
        }
        return $list[0];

    }

    /**
     * メッセージを設定する。
     * @param string $addMsg
     * @param string $msg
     * @param string $replace
     */
    protected function addMessage($addMsg,$msg,$replace = ""){

        if (!empty($replace)){
            $addMsg = str_replace("%s",$replace,$addMsg);
        }

        if (!empty($msg)){
            $msg .= "<br>";
        }

        $msg .= $addMsg;

        return $msg;
    }


    /**
     * ページのHTMLを生成する
     * @param unknown $searchDto
     * @param unknown $dtoList
     * @return string
     */
    function createHtmlPager($searchDto,$dtoList,$sortKey,$syskey){

        // 表示するページ
        $page = $searchDto->getPage();
        if (empty($page)) {
            $page = 1;
        }

        // 1ページに表示する件数
        $listLimit = $searchDto->getListLimit();
        if (empty($listLimit)) {
            $listLimit = MODAL_LIST_LIMIT_DEFAULT;
        }

        // トータル件数
        if (count($dtoList) > 0){
            $totalCount = $dtoList[0]->getTotalCount();
        }else{
            $totalCount = 0;
        }

        // リンク
        //     $link = "http://localhost/env/project/index?page=";
        $link = "../" . $_REQUEST["url"] . "?page=";

        // 表示するボタンの上限数
        $disp = PAGE_BUTTON_MAX;

        // ボタン数 最大値（切り上げ）
        $limit = ceil($totalCount / $listLimit);

        $next = $page + 1;
        $prev = $page - 1;

        // ページ番号リンク用
        $start = ($page - floor($disp / 2) > 0) ? ($page - floor($disp / 2)) : 1; // 始点
        $end = ($start > 1) ? ($page + floor($disp / 2)) : $disp; // 終点
        $start = ($limit < $end) ? $start - ($end - $limit) : $start; // 始点再計算

        $html = '';

        $html .= '					<li class="total">';
        $html .= '						<dl>';
        $html .= '							<dt>件数:</dt>';
        $html .= '							<dd><strong>' . $totalCount . '</strong>件</dd>';
        $html .= '						</dl>';
        $html .= '					</li>';

        $html .= '					<li class="page">';

        $html .= '						<ul>';

        if ($page == 1) {
            $html .= '<li class="off">&#8810; 前へ</li>' . PHP_EOL;
        } else {
            // モーダルの場合は画面自体の再描画を行いたくない為、
            // リンクではなくajax処理でデータを取得する必要がある
            $html .= '<li><a href="#" onclick="modal' . ucfirst($syskey) . 'SearchClick(' . $prev . ');" >&#8810; 前へ</a></li>' . PHP_EOL;
        }

        // 最初のページへのリンク
        if ($start >= floor($disp / 2)) {
            // モーダルの場合は画面自体の再描画を行いたくない為、
            // リンクではなくajax処理でデータを取得する必要がある
            $html .= '<li ><a href="#" onclick="modal' . ucfirst($syskey) . 'SearchClick(1);">' . 1 . '</a></li>' . PHP_EOL;
            if ($start > floor($disp / 2)) {
                // ドットの表示
                $html .= '<li >...</li>' . PHP_EOL;
            }
        }

        for($i = $start; $i <= $end; $i ++) { // ページリンク表示ループ

            $class = ""; // 現在地を表すCSSクラス

            if ($i <= $limit && $i > 0) {
                // 1以上最大ページ数以下の場合
                if ($page == $i) {
                    $html .= '<li class="active">' . ($i) . '</a></li>' . PHP_EOL;
                } else {
                    // ページ番号リンク表示
                    // モーダルの場合は画面自体の再描画を行いたくない為、
                    // リンクではなくajax処理でデータを取得する必要がある
                    $html .= '<li><a href="#" onclick="modal' . ucfirst($syskey) . 'SearchClick(' . $i . ');" >' . ($i) . '</a></li>' . PHP_EOL;
                }
            }
        }

        // 最後のページへのリンク
        if ($limit > $end) {
            if ($limit - 1 > $end) {
                $html .= '<li >...</li>' . PHP_EOL;
            }
            // ページ番号リンク表示
            // モーダルの場合は画面自体の再描画を行いたくない為、
            $html .= '<li><a href="#" onclick="modal' . ucfirst($syskey) . 'SearchClick(' . $limit . ');" >' . ($limit) . '</a></li>' . PHP_EOL;
        }

        if ($page < $limit) {
            // モーダルの場合は画面自体の再描画を行いたくない為、
            // リンクではなくajax処理でデータを取得する必要がある
            $html .= '<li><a href="#"onclick="modal' . ucfirst($syskey) . 'SearchClick(' . $next . ');">次へ &#8811;</a></li>' . PHP_EOL;
        } else {
            $html .= '<li class="off">次へ &#8811;</li>' . PHP_EOL;
        }

        $html .= '						</ul>';

        $html .= '					</li>';

        // 並び順の生成
        $sortDtoList = $this->_getSortDtoList($sortKey);
        $sort2DtoList = $this->_getSortDtoList(SORT_INDEX);

        $html .= '					<li class="order">';
        $html .= '						<dl>';
        $html .= '							<dt>並び順</dt>';
        $html .= '							<dd>';
        $html .= '								<select id="modal_' . $syskey . '_select_sort" name="sort" onchange="modal' . ucfirst($syskey) . 'SearchClick();">';
        $html .= '								' . $this->createSelectHtml($sortDtoList, $searchDto->getSort());
        $html .= '								</select>';
        $html .= '							</dd>';
        $html .= '							<dd>';
        $html .= '								<select id="modal_' . $syskey . '_select_sort2" name="sort2" onchange="modal' . ucfirst($syskey) . 'SearchClick();">';
        $html .= '								' . $this->createSelectHtml($sort2DtoList, $searchDto->getSort2());
        $html .= '								</select>';
        $html .= '							</dd>';
        $html .= '						</dl>';
        $html .= '					</li>';

        return $html;
    }

    function createSelectHtml($dtoList,$check){
        $html = "";

        foreach ( $dtoList as $key => $dto ) {
            $isSelected = "";

            if ($dto->getCode() == $check){
                $isSelected = "selected";
            }

            $html .= "<option value='" . $dto->getCode() . "' " . $isSelected . ">" . $dto->getName() .  "</option>";
        }

        return $html;
    }

    // ディレクトリ階層以下のコピー
    // 引数: コピー元ディレクトリ、コピー先ディレクトリ
    // 戻り値: 結果
    function dir_copy($dir_name, $new_dir)
    {
        if (!is_dir($new_dir)) {
            mkdir($new_dir);
        }

        if (is_dir($dir_name)) {
            if ($dh = opendir($dir_name)) {
                while (($file = readdir($dh)) !== false) {
                    if ($file == "." || $file == "..") {
                        continue;
                    }
                    if (is_dir($dir_name . "/" . $file)) {
                        dir_copy($dir_name . "/" . $file, $new_dir . "/" . $file);
                    }
                    else {
                        copy($dir_name . "/" . $file, $new_dir . "/" . $file);
                    }
                }
                closedir($dh);
            }
        }
        return true;
    }

     /**
     * openSSLを使用した暗号、復号化
     * @param $value:暗号、復号する文字列
     * @param $isEncrypt：true：暗号、false:複合
     * @retrun 結果の文字列
     */
    protected function openSSL($value,$isEncrypt){
        if ($isEncrypt){
            return openssl_encrypt($value,'aes-256-ecb',PROJECT_FORDER);
        }else{
            return openssl_decrypt($value,'aes-256-ecb',PROJECT_FORDER);
        }
    }
}
?>