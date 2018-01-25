<?php
// 表示件数
define('PAGE_BUTTON_MAX',"5");
define('MODAL_LIST_LIMIT_DEFAULT',"5");
define('LIST_LIMIT_DEFAULT',"20");
define('LIST_LIMIT',json_encode([
        [
                'name' => '20',
                'code' => '20',
                'sort_name' => ''
        ],
        [
                'name' => '40',
                'code' => '40',
                'sort_name' => ''
        ],
        [
                'name' => '60',
                'code' => '60',
                'sort_name' => ''
        ],
        [
                'name' => '80',
                'code' => '80',
                'sort_name' => ''
        ],
        [
                'name' => '100',
                'code' => '100',
                'sort_name' => ''
        ]
]));

// 並び順の昇順・降順
define('SORT_INDEX',json_encode([
        [
                'name' => '昇順',
                'code' => '1',
                'sort_name' => 'asc'
        ],
        [
                'name' => '降順',
                'code' => '2',
                'sort_name' => 'desc'
        ]
]));

// オペレータ一覧ソート情報
define('SORT_OPERATOR_INDEX',json_encode([
    [
        'name' => 'ID',
        'code' => '1',
        'sort_name' => 'm_operator.id'
    ],
    [
        'name' => '会社名',
        'code' => '2',
        'sort_name' => 'company.name'
    ],
    [
        'name' => 'オペレータ権限',
        'code' => '3',
        'sort_name' => 'm_operator.permission'
    ],
    [
        'name' => 'ログインID',
        'code' => '4',
        'sort_name' => 'm_operator.login_id'
    ],
    [
        'name' => 'オペレータ名',
        'code' => '5',
        'sort_name' => 'm_operator.operator_name'
    ]
]));

// 会社名一覧ソート情報
define('SORT_COMPANY_INDEX',json_encode([
    [
        'name' => 'ID',
        'code' => '1',
        'sort_name' => 'm_company.id'
    ],
    [
        'name' => '会社名',
        'code' => '2',
        'sort_name' => 'm_company.name'
    ],
    [
        'name' => '住所',
        'code' => '3',
        'sort_name' => 'm_company.address'
    ],
    [
        'name' => '電話番号',
        'code' => '4',
        'sort_name' => 'm_company.phone_number'
    ]
]));

// 住所一覧ソート情報
define('SORT_ADDRESS_INDEX',json_encode([
    [
        'name' => 'ID',
        'code' => '1',
        'sort_name' => 'm_address.id'
    ],
    [
        'name' => '住所ID',
        'code' => '2',
        'sort_name' => 'm_address.id'
    ],
    [
        'name' => '住所名',
        'code' => '3',
        'sort_name' => 'm_address.address_name'
    ],
    [
        'name' => '住所',
        'code' => '4',
        'sort_name' => 'm_address.address'
    ]
]));

// 交通圏一覧ソート情報
define('SORT_LOCATION_INDEX',json_encode([
    [
        'name' => 'ID',
        'code' => '1',
        'sort_name' => 'm_location.id'
    ],
    [
        'name' => '交通圏名称',
        'code' => '2',
        'sort_name' => 'm_location.location_name'
    ]
]));

// 交通圏サブ一覧ソート情報
define('SORT_LOCATION_SUB_INDEX',json_encode([
    [
        'name' => 'ID',
        'code' => '1',
        'sort_name' => 'm_location_sub.id'
    ],
    [
        'name' => '都道府県',
        'code' => '2',
        'sort_name' => 'todohuken_id'
    ],
    [
        'name' => '市区町村',
        'code' => '3',
        'sort_name' => 'm_location_sub.sikutyouson'
    ]
]));

// 営業所一覧ソート情報
define('SORT_OFFICE_INDEX',json_encode([
    [
        'name' => 'ID',
        'code' => '1',
        'sort_name' => 'm_office.id'
    ],
    [
        'name' => '営業所名',
        'code' => '2',
        'sort_name' => 'm_office.office_name'
    ],
    [
        'name' => '会社名',
        'code' => '3',
        'sort_name' => 'company.name'
    ],
    [
        'name' => '住所',
        'code' => '4',
        'sort_name' => 'm_office.address'
    ],
    [
        'name' => '電話番号',
        'code' => '5',
        'sort_name' => 'm_office.phone_number'
    ]
]));

// 車両種別一覧ソート情報
define('SORT_CAR_TYPE_INDEX',json_encode([
    [
        'name' => 'ID',
        'code' => '1',
        'sort_name' => 'm_car_type.id'
    ],
    [
        'name' => '会社名',
        'code' => '2',
        'sort_name' => 'company.name'
    ],
    [
        'name' => '車両種別名',
        'code' => '3',
        'sort_name' => 'm_car_type.car_type_name'
    ]
]));

// 車両一覧ソート情報
define('SORT_CAR_INDEX',json_encode([
    [
        'name' => 'ID',
        'code' => '1',
        'sort_name' => 'm_car.id'
    ],
    [
        'name' => '会社名',
        'code' => '2',
        'sort_name' => 'company.name'
    ],
    [
        'name' => '営業所名',
        'code' => '3',
        'sort_name' => 'office.office_name'
    ],
    [
        'name' => '車両種別',
        'code' => '4',
        'sort_name' => 'car_type.car_type_name'
    ],
    [
        'name' => '車両番号',
        'code' => '5',
        'sort_name' => 'm_car.car_number'
    ]
]));

// 料金一覧ソート情報
define('SORT_RYOUKIN_INDEX',json_encode([
    [
        'name' => 'ID',
        'code' => '1',
        'sort_name' => 'm_ryoukin.id'
    ],
    [
        'name' => '交通圏名称',
        'code' => '2',
        'sort_name' => 'location.location_name'
    ],
    [
        'name' => '初乗運賃',
        'code' => '3',
        'sort_name' => 'm_ryoukin.hatunori_untin'
    ],
    [
        'name' => '初乗距離',
        'code' => '4',
        'sort_name' => 'm_ryoukin.hatunori_kyori'
    ],
    [
        'name' => '加算運賃',
        'code' => '5',
        'sort_name' => 'm_ryoukin.kasan_untin'
    ],
    [
        'name' => '加算距離',
        'code' => '6',
        'sort_name' => 'm_ryoukin.kasan_kyori'
    ]

]));

// 歴史一覧ソート情報
define('SORT_HISTORY_INDEX',json_encode([
    [
        'name' => 'ID',
        'code' => '1',
        'sort_name' => 't_pickup.id'
    ],
    [
        'name' => '迎車ステータス',
        'code' => '2',
        'sort_name' => 't_pickup.pickup_status'
    ],
    [
        'name' => '依頼元',
        'code' => '3',
        'sort_name' => 't_pickup.request_type'
    ],
    [
        'name' => '会社名',
        'code' => '4',
        'sort_name' => 'company.name'
    ],
    [
        'name' => '顧客名',
        'code' => '5',
        'sort_name' => 'client.name'
    ],
    [
        'name' => '顧客電話番号',
        'code' => '6',
        'sort_name' => 'client.phone_number'
    ],
    [
        'name' => '迎車日時 ',
        'code' => '7',
        'sort_name' => 't_pickup.insert_date'
    ]
]));

// 顧客一覧ソート情報
define('SORT_CLIENT_INDEX',json_encode([
    [
        'name' => 'ID',
        'code' => '1',
        'sort_name' => 'm_client.id'
    ],
    [
        'name' => '登録元区分',
        'code' => '2',
        'sort_name' => 'm_client.register_type'
    ],
    [
        'name' => '顧客名',
        'code' => '3',
        'sort_name' => 'm_client.name'
    ],
        [
        'name' => '電話番号',
        'code' => '4',
        'sort_name' => 'm_client.phone_number'
    ],
    [
        'name' => '不正利用回数',
        'code' => '5',
        'sort_name' => 'm_client.invalid_used_num'
    ],
    [
        'name' => '利用フラグ',
        'code' => '6',
        'sort_name' => 'm_client.riyou_flg'
    ]
]));

// 乗務員一覧ソート情報
define('SORT_DRIVER_INDEX',json_encode([
    [
        'name' => 'ID',
        'code' => '1',
        'sort_name' => 'm_driver.id'
    ],
    [
        'name' => '会社名',
        'code' => '2',
        'sort_name' => 'company.name'
    ],
    [
        'name' => '社員番号',
        'code' => '3',
        'sort_name' => 'm_driver.syain_no'
    ],
    [
        'name' => '乗務員名',
        'code' => '4',
        'sort_name' => 'm_driver.driver_name'
    ],
    [
        'name' => '電話番号',
        'code' => '5',
        'sort_name' => 'm_driver.phone_number'
    ]
]));
// お知らせ(顧客向け)検索・一覧ソート情報
define('SORT_MESSAGE_TO_CLIENT_INDEX',json_encode([
    [
        'name' => 'ID',
        'code' => '1',
        'sort_name' => 't_message_to_client.id'
    ],
    [
        'name' => 'フラグ',
        'code' => '2',
        'sort_name' => 't_message_to_client.flag'
    ],
    [
        'name' => '配信開始日',
        'code' => '3',
        'sort_name' => 't_message_to_client.start_date'
    ],
    [
        'name' => '配信終了日',
        'code' => '4',
        'sort_name' => 't_message_to_client.end_date'
    ]
]));
// 乗務員評価検索・一覧ソート情報
define('SORT_DRIVER_HYOUKA_INDEX',json_encode([
    [
        'name' => 'ID',
        'code' => '1',
        'sort_name' => 't_driver_hyouka.id'
    ],
    [
        'name' => '会社名',
        'code' => '2',
        'sort_name' => 'company.name'
    ],
    [
        'name' => '乗務員名',
        'code' => '3',
        'sort_name' => 'driver.driver_name'
    ],
    [
        'name' => '評価',
        'code' => '4',
        'sort_name' => 't_driver_hyouka.hyouka'
    ],
    [
        'name' => '登録日時',
        'code' => '5',
        'sort_name' => 't_driver_hyouka.insert_date'
    ]
]));
// タブレット・一覧ソート情報
define('SORT_TABLET_INDEX',json_encode([
    [
        'name' => 'ID',
        'code' => '1',
        'sort_name' => 'm_tablet.id'
    ],
    [
        'name' => '会社名',
        'code' => '2',
        'sort_name' => 'company.name'
    ],
    [
        'name' => '端末ID',
        'code' => '3',
        'sort_name' => 'm_tablet.tanmatu_id'
    ],
    [
        'name' => '端末名',
        'code' => '4',
        'sort_name' => 'm_tablet.tanmatu_name'
    ],
    [
        'name' => '利用フラグ',
        'code' => '5',
        'sort_name' => 'm_tablet.riyou_flg'
    ],
    [
        'name' => '接続状況',
        'code' => '6',
        'sort_name' => 'tablet_riyou.post_date'
    ]
]));
// お知らせ一覧（乗務員向け）・一覧ソート情報
define('SORT_MESSAGE_TO_DRIVER_INDEX',json_encode([
    [
        'name' => 'ID',
        'code' => '1',
        'sort_name' => 't_message_to_driver.id'
    ],
    [
        'name' => '会社',
        'code' => '2',
        'sort_name' => 'company.name'
    ],
    [
        'name' => 'フラグ',
        'code' => '3',
        'sort_name' => 't_message_to_driver.flag'
    ],
    [
        'name' => '配信開始日',
        'code' => '4',
        'sort_name' => 't_message_to_driver.start_date'
    ],
    [
        'name' => '配信終了日',
        'code' => '5',
        'sort_name' => 't_message_to_driver.end_date'
    ]
]));
?>