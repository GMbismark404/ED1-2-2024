object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 738
  ClientWidth = 972
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object CrearSM: TButton
    Left = 8
    Top = 64
    Width = 121
    Height = 25
    Caption = 'Crear SM'
    TabOrder = 0
    OnClick = CrearSMClick
  end
  object PedirEspacio: TButton
    Left = 8
    Top = 112
    Width = 121
    Height = 25
    Caption = 'Pedir Espacio'
    TabOrder = 1
    OnClick = PedirEspacioClick
  end
  object LiberarEspacio: TButton
    Left = 8
    Top = 160
    Width = 121
    Height = 25
    Caption = 'Liberar Espacio'
    TabOrder = 2
    OnClick = LiberarEspacioClick
  end
  object CrearLista: TButton
    Left = 8
    Top = 256
    Width = 121
    Height = 25
    Caption = 'Crear Lista'
    TabOrder = 3
    OnClick = CrearListaClick
  end
  object InsertarInicio: TButton
    Left = 8
    Top = 304
    Width = 121
    Height = 25
    Caption = 'Insertar Inicio'
    TabOrder = 4
    OnClick = InsertarInicioClick
  end
  object InsertarFinal: TButton
    Left = 8
    Top = 352
    Width = 121
    Height = 25
    Caption = 'Insertar Final'
    TabOrder = 5
    OnClick = InsertarFinalClick
  end
  object MostrarMemoria: TButton
    Left = 8
    Top = 400
    Width = 121
    Height = 25
    Caption = 'Mostar Memoria'
    TabOrder = 6
    OnClick = MostrarMemoriaClick
  end
  object MostrarLista: TButton
    Left = 8
    Top = 448
    Width = 121
    Height = 25
    Caption = 'Mostrar Lista'
    TabOrder = 7
    OnClick = MostrarListaClick
  end
  object Edit1: TEdit
    Left = 144
    Top = 113
    Width = 120
    Height = 23
    TabOrder = 8
    TextHint = 'ci,fono,edad'
  end
  object Edit2: TEdit
    Left = 144
    Top = 161
    Width = 57
    Height = 23
    TabOrder = 9
    TextHint = 'dir'
  end
  object Edit3: TEdit
    Left = 144
    Top = 305
    Width = 57
    Height = 23
    TabOrder = 10
    TextHint = 'valor'
  end
  object Edit4: TEdit
    Left = 144
    Top = 353
    Width = 57
    Height = 23
    TabOrder = 11
    TextHint = 'valor'
  end
  object Edit5: TEdit
    Left = 144
    Top = 401
    Width = 57
    Height = 23
    TabOrder = 12
    Text = '0'
  end
  object Edit6: TEdit
    Left = 207
    Top = 401
    Width = 57
    Height = 23
    TabOrder = 13
    Text = '11'
  end
  object Edit7: TEdit
    Left = 144
    Top = 449
    Width = 57
    Height = 23
    TabOrder = 14
    Text = '0'
  end
  object Edit8: TEdit
    Left = 207
    Top = 449
    Width = 57
    Height = 23
    TabOrder = 15
    Text = '11'
  end
  object Edit9: TEdit
    Left = 144
    Top = 209
    Width = 57
    Height = 23
    TabOrder = 16
    TextHint = 'dir'
  end
  object Edit10: TEdit
    Left = 207
    Top = 209
    Width = 57
    Height = 23
    TabOrder = 17
    TextHint = 'id'
  end
  object Edit11: TEdit
    Left = 270
    Top = 209
    Width = 51
    Height = 23
    TabOrder = 18
    TextHint = 'valor'
  end
  object PonerDato: TButton
    Left = 8
    Top = 208
    Width = 121
    Height = 25
    Caption = 'Poner Dato'
    TabOrder = 19
    OnClick = PonerDatoClick
  end
  object Button1: TButton
    Left = 40
    Top = 520
    Width = 75
    Height = 25
    Caption = 'Button1'
    TabOrder = 20
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 40
    Top = 559
    Width = 75
    Height = 25
    Caption = 'Button2'
    TabOrder = 21
    OnClick = Button2Click
  end
end
