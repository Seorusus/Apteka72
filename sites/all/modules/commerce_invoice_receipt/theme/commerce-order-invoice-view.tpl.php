<html>
  <head>
    <meta http-equiv="Content-Type" content="text/html;charset=utf-8" />
  </head>
  <body>
    <table width="100%" border="0" cellspacing="0" cellpadding="1" align="center" bgcolor="#CCC">
      <tr>
        <td>
          <table width="100%" border="0" cellspacing="0" cellpadding="5" align="center" bgcolor="#FFF" style="font-family: verdana, arial, helvetica; font-size: 10px;">
            <tr>
              <td>
                <table width="100%" border="0" cellspacing="0" cellpadding="0" style="font-family: verdana, arial, helvetica; font-size: 11px;">
                  <tr>
                    <td nowrap="nowrap" style="line-height: 1.6em;" valign="middle">
											<!-- Invoice Header -->
											<img src="<?php print $info['site_logo']; ?>" />
                    </td>
                    <td nowrap="nowrap" style="line-height: 1.6em;" valign="middle" align="right">
                    Зеленая Аптека<br>
                    Мельникайте, 135<br>
                    625007 Тюмень<br>
                    (3452) 34-98-54</td>
                  </tr>
                </table>
              </td>
            </tr>
            <tr>
              <td>
                <table width="100%" border="0" cellspacing="0" cellpadding="0" style="font-family: verdana, arial, helvetica; font-size: 11px;">
                  <tr>
                    <th colspan="2"><?php print t('Order Summary'); ?></th>
                  </tr>
                  <tr>
                    <td colspan="2">

                      <table class="details" width="100%" cellspacing="0" cellpadding="0" style="font-family: verdana, arial, helvetica; font-size: 1em;">
                        <tr>
                          <td valign="top" width="50%">
                            <br/>
                            <b>Покупатель</b> <?php print $info['order_u_name']; ?><br/>
                            <br/>
                            <b>Адрес электр. почты</b> <?php print $info['order_mail']; ?><br/>
                            <br/>
                            <b>Дата заказа</b> <?php print format_date($info['order_created']); ?><br/><br/>
                            <b>Номер заказа</b> <?php print $info['order_number']; ?>
                          </td>
                          <td valign="top" width="50%">
                            <b>Адрес доставки:</b><br />
                            <?php print isset($info['customer_billing']) ? $info['customer_billing'] : ''; ?><br />
                          </td>
                        </tr>
                      </table>

                    </td>
                  </tr>
                </table>
              </td>
            </tr>
            <tr>
              <td>
                <table class="products" width="100%" border="0" cellspacing="0" cellpadding="0" align="center" style="font-family: verdana, arial, helvetica; font-size: 11px;">
                  <tbody>
                    <tr>
                      <td class="line-items"><?php print isset($info['line_items']) ? $info['line_items'] : ''; ?></td>
                    </tr>
                    <tr>
                      <td><?php print isset($info['order_total']) ? $info['order_total'] : ''; ?></td>
                    </tr>
                  </tbody>
                </table>
              </td>
            </tr>
            <!--             <tr>
                         <td>
                           <table>
                             <tr>
                               <td colspan="2" style="background: #EEE; color: #666; padding: 1em; font-size: 0.9em; line-height: 1.6em; border-top: #CCC 1px dotted;align: center;">
                                 <!-- Invoice Header
                                                       [INSERT FOOTER]
                               </td>
                             </tr>
                           </table>
              </td>
            </tr> -->
          </table>
        </td>
      </tr>
    </table>
    <?php if( $mode == 'print'){ ?>
    <div align="right" style="margin-top: 1em; margin-right: 1em;"><input type="button" value="Распечатать" onclick="window.print();" /> <input type="button" value="Закрыть окно" onclick="window.close();" /></div>
    <?php } ?>
  </body>
</html>
